#lang racket

(define xs (list 1 2 3 4))

(define (elem? x xs)
       (if (equal? xs null) #f
           (if (equal? x (car xs)) #t
               (elem? x (cdr xs)))))