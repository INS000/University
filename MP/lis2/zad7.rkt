#lang racket

(define xs (list 1 2 3 4))

(define (suffixes xs)
  (if (null? xs) (list (list))
      (cons xs (suffixes (cdr xs)))))