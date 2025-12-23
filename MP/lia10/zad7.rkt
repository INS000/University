#lang plait

(define-syntax my-and
  (syntax-rules ()
    [(my-and) #t]
    [(my-and x1 x2 ...)
     (if x1
         (my-and x2 ...)
         #f)]))


(define-syntax my-or
  (syntax-rules ()
    [(my-or) #f]
    [(my-or x1 x2 ...)
       (if x1
           #t
           (my-or x2 ...))]))



(my-and (= 2 2) (> 3 2) (< 4 5))

(my-or (= 2 2) (> 3 2) (< 4 5))

(my-and (= 2 2) (< 3 2) (> 4 5))

(my-or (= 2 2) (< 3 2) (> 4 5))

(define-syntax my-let
  (syntax-rules ()
    [(my-let () a) a]
    [(my-let ([x1 a1] [x2 a2] ...) body)
     ((lambda (x1 x2 ...) body) a1 a2 ...)]))

(define-syntax my-let*
  (syntax-rules ()
    [(my-let* () a) a]
    [(my-let* ([x1 a1] [x2 a2] ...) body)
     ((lambda (x1) (my-let* ([x2 a2] ...) body)) a1)]))

(my-let ((x 2)
          (y 3))
  (+ x y))

(my-let* ((x 1)
          (y (+ x 2))
          (z (+ y 1)))
  (+ x z))
