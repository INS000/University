#lang racket

(define (llist Ls)
  (lambda (xs) (append Ls xs)))

(define f (llist (list 1 2)) )

(f '(3 4))

(define (list->llist x)
  (lambda(y)(foldr cons y x)))

(define (llist->list f)
  (f '()))

(define (llist-singleton x) (list->llist (list x)))

(define (list-append f g)
  (lambda(x)(f(g x))))

( define ( foldr-reverse xs )
( foldr ( lambda ( y ys ) ( llist-append ys ( list y ) ) ) null xs ) )