#lang racket

(require rackunit)

(define (+2grsq x y z) (cond ([and (<= x y) (<= x z)] [+ (* y y) (* z z)])
                             ([and (<= y z) (<= y x)] [+ (* x x) (* z z)])
                             (else [+ (* x x) (* y y)])))

(check-true (number? (+2grsq 1 2 3)))
(check-true (number? (+2grsq 2 2 2)))

(check-equal? (+2grsq 1 2 3) 13)
(check-equal? (+2grsq 1 3 2) 13)
(check-equal? (+2grsq 2 1 3) 13)
(check-equal? (+2grsq 2 3 1) 13)
(check-equal? (+2grsq 3 1 2) 13)
(check-equal? (+2grsq 3 2 1) 13)
(check-equal? (+2grsq 1 1 2) 5)