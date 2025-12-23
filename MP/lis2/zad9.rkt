#lang racket

(define (minimum xs)
	(define (minipomoc xs x)
		(cond [(empty? xs) x]
		[(< (car xs) x) (minipomoc (cdr xs) (car xs))]
		[else (minipomoc (cdr xs) x)]))
	(minipomoc xs +inf.0))


(define (notx x xs)
  (cond [(null? xs) (list)]
        [(equal? (car xs) x) (cdr xs)]
        [else (cons (car xs) (notx x (cdr xs)))]))

(define (selsort xs)
  (if (empty? xs) null
      (cons (minimum xs) (selsort (notx (minimum xs) xs)))))