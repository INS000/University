#lang plait
( define-type ( NNF 'v)
   ( nnf-lit [ polarity : Boolean ] [ var : 'v ])
   ( nnf-conj [l : ( NNF 'v)] [r : ( NNF 'v) ])
   ( nnf-disj [l : ( NNF 'v)] [r : ( NNF 'v) ]) )

(define (neg-nnf f)
  (cond ((nnf-lit? f) (nnf-lit (not (nnf-lit-polarity f)) (nnf-lit-var f)))
        ((nnf-conj? f) (nnf-disj (neg-nnf (nnf-conj-l f)) (neg-nnf (nnf-conj-r f))))
        ((nnf-disj? f) (nnf-conj (neg-nnf (nnf-disj-l f)) (neg-nnf (nnf-disj-r f))))))

(define (eval-nnf val f)
    (cond ((nnf-lit? f) (equal? (not (nnf-lit-polarity f)) (wart (nnf-lit-var f))))
         ((nnf-conj? f) (and (eval-nnf wart (nnf-conj-l f)) (eval-nnf wart (nnf-conj-r f))))
         ((nnf-disj? f) (or (eval-nnf wart (nnf-disj-l f)) (eval-nnf wart (nnf-disj-r f))))))


(define (my-wart v)
   (cond ((equal? v "p") #t)
         ((equal? v "q") #f)
         (else #t)))

(define my-nnf
   (nnf-conj (nnf-lit #t "p") (nnf-disj (nnf-lit #t "p") (nnf-lit #f "q"))))

( define-type ( Formula 'v)
   ( var [ var : 'v ])
   ( neg [ f : ( Formula 'v) ])
   ( conj [ l : ( Formula 'v)] [r : ( Formula 'v) ])
   ( disj [ l : ( Formula 'v)] [r : ( Formula 'v) ]))

(define (to-nnf p)
  (type-case (Formula 'v) p
    [(var a) (nnf-lit #t a)]
    [(neg a) (neg-nnf (to-nnf a))]
    [(conj l r) (nnf-conj (to-nnf l) (to-nnf r))]
    [(disj l r) (nnf-disj (to-nnf l) (to-nnf r))]))

; (define (to-nnf p)
;   (cond ((var? p) (nnf-lit #t (var-nn)))
;          ((neg? p) (neg-nnf (to-nnf )))))