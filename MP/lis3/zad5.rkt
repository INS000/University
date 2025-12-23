#lang racket

(define (negatives n)
  (build-list n (lambda (x) (- -1 x))))

(define (reciprocals n)
  (build-list n (lambda (x) (/ 1 (+ x 1)))))

(define (evens n)
  (build-list n (lambda (x) (* x 2))))

(define (rec n x)
  (if (= n 0) (list)
      (if (= n (+ x 1)) (cons 1 (rec (- n 1) x))
          (cons 0 (rec (- n 1) x) ) ) ) )

(define (identityM n)
  (build-list n (lambda (x) (rec n (- (- n x) 1)))))