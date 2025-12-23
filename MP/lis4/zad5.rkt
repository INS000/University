#lang racket

(define-struct leaf () #:transparent)
(define-struct node (l elem r) #:transparent)

( define t
   ( node
     ( node ( leaf ) 2 ( leaf ) )
     5
     ( node ( node ( leaf ) 6 ( leaf ) )
           8
           ( node ( leaf ) 9 ( leaf ) ) ) ) )

(define (insert-bst-pow x t)
  (cond [(leaf? t) (node (leaf) x (leaf))]
        [(node? t)
         (cond [(< x (node-elem t))
                 (node (insert-bst-pow x (node-l t))
                       (node-elem t)
                       (node-r t))]
                [else
                 (node (node-l t)
                       (node-elem t)
                       (insert-bst-pow x (node-r t)))])]))

(define (fold-tree f x tree)
  (if (leaf? tree)
      x
      (f (node-elem tree) (fold-tree f x (node-l tree)) (fold-tree f x (node-r tree)))))

(define (flatten t)
  (fold-tree (lambda (elem l r) (append l (cons elem r))) '() t))

(define (treesort xs)
  (define (pom xs t)
    (if (empty? xs) (flatten t)
        (pom (cdr xs) (insert-bst-pow (car xs) t))))
  (pom xs (leaf)))

(define l '(5 3 2 7 8))

(treesort '(5 3 2 7 8))
  