#lang racket

(define (fib n)
  (if  (= n 0) 0
       (if (= n 1) 1
           (+ (fib (- n 1)) (fib (- n 2))))))

(define (fib-iter n)
  (define (iter n a b)
    (if (= n 0) a
        (iter (- n 1) b (+ b a))))
  (iter n 0 1))

(fib-iter 40)
