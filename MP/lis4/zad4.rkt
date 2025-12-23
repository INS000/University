#lang racket

(define (flatten-tree tree)
  (define (flat-append t xs)
    (if (leaf? t)
        xs
        (flat-append (node-l t)
                     (cons (node-elem t)
                           (flat-append (node-r t) xs)))))
  (flat-append tree '()))