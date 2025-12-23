#lang plait

(define-type UnaryOp
  (op-neg) (op-fact))

(define-type BinaryOp
  (op-add) (op-mul) (op-sub) (op-div) (op-pow))

(define-type Exp
  (exp-number [n : Number])
  (exp-unary-op [op : UnaryOp] [e : Exp])
  (exp-binary-op [op : BinaryOp] [e1 : Exp] [e2 : Exp]))

(define (parse-UnaryOp s)
  (let ([sym (s-exp->symbol s)])
  (cond
    [(equal? sym '!) (op-fact)]
    [(equal? sym '~) (op-neg)])))


(define (parse-BinaryOp s)
  (let ([sym (s-exp->symbol s)])
  (cond
    [(equal? sym '+) (op-add)]
    [(equal? sym '-) (op-sub)]
    [(equal? sym '*) (op-mul)]
    [(equal? sym '/) (op-div)]
    [(equal? sym '^) (op-pow)])))

(define (helper a b wyn)
        (if (= b 0)
            wyn
            (helper a (- b 1) (* a wyn))))

(define (^ x y)
    (if (> y 0)
        (helper x y 1)
        (helper (/ 1 x) (- 0 y) 1)))

(define (~ x)
    (* -1 x))

(define (! x)
    (if (= x 0)
        1
        (* x (! (- x 1)))))


(define (eval-binary-op op)
  (type-case BinaryOp op
    [(op-add) +]
    [(op-sub) -]
    [(op-mul) *]
    [(op-div) /]
    [(op-pow) ^]))

(define (eval-unary-op op)
  (type-case UnaryOp op
    [(op-neg) ~]
    [(op-fact) !]))

(define (eval e)
  (type-case Exp e
    [(exp-number n)    n]
    [(exp-unary-op op e) ((eval-unary-op op) (eval e))]
    [(exp-binary-op op e1 e2) ((eval-binary-op op) (eval e1) (eval e2))]))


(define (parse-Exp s)
  (cond
    [(s-exp-number? s) (exp-number (s-exp->number s))]
    [(s-exp-list? s)
     (let ([xs (s-exp->list s)])
        (if (= 3 (length xs))
            (exp-binary-op (parse-BinaryOp  (first  xs))
                (parse-Exp (second xs))
                (parse-Exp (third  xs)))
            (exp-unary-op (parse-UnaryOp (first  xs))
                (parse-Exp (second xs)))))]))

(define (eval-Exp s)
    (eval (parse-Exp s)))
