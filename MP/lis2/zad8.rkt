#lang racket

(define xs (list 1 2 3 3))

(define (sorted? xs)
  (if (null?  xs) #t 
    (if (null? (cdr xs)) #t  
       (if (> (car xs) (car (cdr xs))) #f
           (sorted? (cdr xs))))))