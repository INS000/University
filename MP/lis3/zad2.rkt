#lang racket

(define (product xs)
  (if (null? xs) 0
      (foldl * 1 xs)))