#lang racket

(define empty-queue (cons '() '()))

(define (empty? q)
  (null? (car q)))

(define (push-back x q)
  (if (empty? q)
      (cons (list x) '())
       (cons (car q) (cons x (cdr q)))))

(define (front q)
  (car (car q)))

(define (pop q)
  (cond
    [(empty? q) empty-queue]
    [(null? (cdr(car q))) 
      (cons (reverse (cdr q)) '())]
    [else
      (cons (cdr (car q)) (cdr q))]))