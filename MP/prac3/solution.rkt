#lang plait

(define-type-alias Value Number)

(define-type Op
  (add) (sub) (mult) (leq))

(define-type Pxp
  (defE [d : (Listof Dxp)] [e : Exp]))

(define-type Dxp
  (funE [f : Symbol] [x : (Listof Symbol)] [e : Exp]))

(define-type Exp
  (numE [n : Number])
  (varE [x : Symbol])
  (opE [e1 : Exp] [⊕ : Op] [e2 : Exp])
  (ifz [e0 : Exp] [e1 : Exp] [e2 : Exp])
  (letE [x : Symbol] [e1 : Exp] [e2 : Exp])
  (fE [f : Symbol] [e : (Listof Exp)]))

(define (parseE [s : S-Exp]) : Exp
  (cond
    [(s-exp-match? `NUMBER s)
     (numE (s-exp->number s))]
    [(s-exp-match? `SYMBOL s)
     (varE (s-exp->symbol s))]
    [(s-exp-match? `{ANY SYMBOL ANY} s)
     (opE (parseE (first (s-exp->list s)))
          (parse-op (s-exp->symbol (second (s-exp->list s))))
          (parseE (third (s-exp->list s))))]
    [(s-exp-match? `{ifz ANY then ANY else ANY} s)
     (ifz (parseE (second (s-exp->list s)))
          (parseE (fourth (s-exp->list s)))
          (parseE (list-ref (s-exp->list s) 5)))]
    [(s-exp-match? `{let SYMBOL be ANY in ANY} s)
     (letE (s-exp->symbol (second (s-exp->list s)))
           (parseE (fourth (s-exp->list s)))
           (parseE (list-ref (s-exp->list s) 5)))]
    [(s-exp-match? `{SYMBOL (ANY ...)} s)
     (fE (s-exp->symbol (first (s-exp->list s)))
         (map parseE (s-exp->list (second (s-exp->list s)))))]
    [else (error 'parse "invalid input")]))

(define (parse-op [op : Symbol]) : Op
  (cond
    [(eq? op '+) (add)]
    [(eq? op '-) (sub)]
    [(eq? op '*) (mult)]
    [(eq? op '<=) (leq)]
    [else (error 'parse "unknown operator")]))

(define (last l)
  (first (reverse l)))

(define (parseD [s : S-Exp]) : Dxp
  (cond
    [(s-exp-match? `{fun SYMBOL (SYMBOL ...) = ANY} s)
     (funE (s-exp->symbol (second (s-exp->list s)))
           (map s-exp->symbol (s-exp->list (third (s-exp->list s))))
           (parseE (list-ref (s-exp->list s) 4)))]
    [else (error 'parse "invalid input")]))

(define (parse [s : S-Exp]) : Pxp
  (cond
    [(s-exp-match? `{define (ANY ...) for ANY} s)
     (defE (map parseD (s-exp->list (second (s-exp->list s))))
       (parseE (fourth (s-exp->list s))))]
    [else (error 'parse "invalid input")]))

(define (lesseq  a b)
  (if (<= a b) 0 2137))

(define (op->proc [op : Op]) : (Value Value -> Value)
  (type-case Op op
    [(add) +]
    [(sub) -]
    [(mult) *]
    [(leq) lesseq]))

(define-type Binding
  (bind [name : Symbol]
        [val : Value]))

(define-type Binding2
  (bind2 [name : Symbol]
         [arg : (Listof Symbol)]
         [body : Exp]))

(define-type-alias Env (Listof Binding))

(define-type-alias Env2 (Listof Binding2))

(define mt-env empty)

(define (extend-env [env : Env] [x : Symbol] [v : Value]) : Env
  (cons (bind x v) env))

(define (extend-env2 [env : Env2] [x : Symbol] [y : (Listof Symbol)] [v : Exp]) : Env2
  (cons (bind2 x y v) env))

(define (lookup-env [n : Symbol] [env : Env]) : Value
  (type-case (Listof Binding) env
    [empty (error 'lookup "unbound variable")]
    [(cons b rst-env) (cond
                        [(eq? n (bind-name b))
                         (bind-val b)]
                        [else (lookup-env n rst-env)])]))

(define (lookup-env2 [n : Symbol] [env : Env2]) : ((Listof Symbol) * Exp )
  (type-case (Listof Binding2) env
    [empty (error 'lookup "unbound variable")]
    [(cons b rst-env) (cond
                        [(eq? n (bind2-name b))
                         (pair (bind2-arg b) (bind2-body b))]
                        [else (lookup-env2 n rst-env)])]))

(define (args-with-vals [a : (Listof Symbol)] [vals : (Listof Value)] [env : Env])
  (if (= (length a) (length vals))
      (if (= (length a) 1)
          (extend-env env (first a) (first vals))
          (args-with-vals (rest a) (rest vals) (extend-env env (first a) (first vals))))
      (error 'arguments "size of lists not equal")))

(define (evalE [e : Exp] [env : Env] [env2 : Env2]) : Value
  (type-case Exp e
    [(numE n) n]
    [(varE x) (lookup-env x env)]
    [(opE l o r) ((op->proc o) (evalE l env env2) (evalE r env env2))]
    [(ifz b l r)
     (if (= (evalE b env env2) 0)
         (evalE l env env2)
         (evalE r env env2))]
    [(letE x e1 e2)
     (let ([v1 (evalE e1 env env2)])
       (evalE e2 (extend-env env x v1) env2))]
    [(fE f a)
     (evalE (snd (lookup-env2 f env2)) (args-with-vals (fst (lookup-env2 f env2)) (map (lambda (x) (evalE x env env2)) a) mt-env) env2)]))

(define (gen-env2 [l : (Listof Dxp)] [env : Env2])
  (if (empty? l)
      env
      (gen-env2 (rest l) (extend-env2 env (funE-f (first l)) (funE-x (first l)) (funE-e (first l))))))

(define (eval [p : Pxp])
  (evalE (defE-e p) mt-env (gen-env2 (defE-d p) mt-env)))

(define (run [s : S-Exp]) : Value
  (eval (parse s)))


#;(module+ test
  (print-only-errors #t))

#;(module+ test
  (test (run `{define
                 {[fun fact (n) = {ifz n then 1 else {n * {fact ({n - 1})}}}]}
                for
                 {fact (5)}}) 120)
  (test (run `{define
                {[fun even (n) = {ifz n then 0 else {odd ({n - 1})}}]
                 [fun odd (n) = {ifz n then 42 else {even ({n - 1})}}]}
                for
                 {even (1024)}}) 0)
  (test (run `{define
                {[fun gcd (m n) = {ifz n then m else {ifz {m <= n}
                                                          then {gcd (m {n - m})}
                                                          else {gcd ({m - n} n)}}}]}
                for
                 {gcd (81 63)}}) 9))



