#lang racket

(define (myreverse! xs)
    (define (reverse-pom prev curr)
        (if (null? curr)
            prev
            (let ([next (mcdr curr)])
              (set-mcdr! curr prev)
              (reverse-pom curr (mcdr curr)))))
    (reverse-pom (list) xs))


(define ys (mcons 1 (mcons 2 (mcons 3 null))))
