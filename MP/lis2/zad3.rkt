#lang racket

(require rackunit)

;zad 3

(define-struct matrix (a b c d))

(define (matrix-mult m n)
  (make-matrix
  (+ (* (matrix-a m) (matrix-a n)) (* (matrix-b m) (matrix-c n)))
  (+ (* (matrix-a m) (matrix-b n)) (* (matrix-b m) (matrix-d n)))
  (+ (* (matrix-c m) (matrix-a n)) (* (matrix-d m) (matrix-c n)))
  (+ (* (matrix-c m) (matrix-b n)) (* (matrix-d m) (matrix-d n)))))

(define matrix-id (make-matrix 1 0 0 1))

(define fibohelper (make-matrix 1 1 1 0))

(define t1 (make-matrix 10 13 6 9))
(define t2 (make-matrix 21 37 13 0))
(define t3 (make-matrix 3 2 5 7))


(define (matrix-expt m k)
  (if (= k 0) matrix-id
      (matrix-mult m (matrix-expt m (- k 1)))))

(define (fib-matrix k)
  (matrix-b (matrix-expt fibohelper k)))



;zad 4

(define (matrix-expt-fast m k)
  (cond
    [(= k 0) matrix-id]
    [(even? k) (matrix-expt-fast (matrix-mult m m) (/ k 2))]
    [else (matrix-mult m (matrix-expt-fast (matrix-mult m m) (/ [- k 1] 2)))]))

(define (fib-fast k) 
  (matrix-a (matrix-expt-fast fibohelper (- k 1))))
