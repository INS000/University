#lang racket

(define xs (list 1 2 3 4))

(define (maximum xs)
  (define (maxl xs x)
    (if (equal? xs null) x
     (if (> (car xs) x) (maxl (cdr xs) (car xs))
         (maxl (cdr xs) x))))
  (maxl xs -inf.0))