#lang racket

;( parametric- >/ c [a b] (- > a b a))
;                                  |
(define/contract (first a b)
    (parametric->/c [a b] (-> a b a))
        a
)

;( parametric- >/ c [a b c] (- > (- > a b c) (- > a b) a c))
;                                     | |         |      |
(define/contract (fun f g x)
    (parametric->/c [a b c] (-> (-> a b c) (-> a b) a c))
  (f x (g x))
)

;( parametric- >/ c [a b c] (- > (- > b c) (- > a b) (- > a c)))
;                                     |         |           |
(define/contract (fun3 f g)
  (parametric->/c [a b c] (- > (- > b c) (- > a b) (- > a c)))
  (lambda (x) (f (g x)))
  )

;( parametric- >/ c [a] (- > (- > (- > a a) a) a))
;                                        |     |
(define/contract (fun4 x)
  (parametric->/c [a] (-> (-> (-> a a) a) a))
  (define (ident x) x)
  (define (pom h ii) (ii (h ii)))
  (pom x ident)
  )