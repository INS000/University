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


(define h
  (node
   (node
    (node
     (node (leaf) 11 (leaf))
      3
      (leaf))
     8
     (leaf))
   5
   (node
    (leaf)
    9
    (node (leaf) 6 (leaf)))))

(define (fold-tree f x tree)
  (if (leaf? tree)
      x
      (f (node-elem tree) (fold-tree f x (node-l tree)) (fold-tree f x (node-r tree)))))

(define (tree-sum t)
  (fold-tree + 0 t))

(define (tree-flip t)
  (fold-tree (lambda (e l r) (node r e l)) (leaf) t))

(define (tree-height t)
  (fold-tree (lambda (e l r) (+ 1 (max l r))) 0 t))

(define (maxl t)
  (if (leaf? node-l) node-elem (maxl node-l)))

(define (maxr t)
  (if (leaf? node-r) node-elem (maxl node-r)))


(define (tree-span t)
  (cons (fold-tree (lambda (e l r) (if (leaf? l) e l)) (leaf) t) (fold-tree (lambda (e l r) (if (leaf? r) e r)) (leaf) t)))
 

(define (flatten t)
  (fold-tree (lambda (elem l r) (append l (cons elem r))) '() t))



