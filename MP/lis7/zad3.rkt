#lang racket

(define/contract (suffixes xs)
  (parametric->/c [a] (-> (listof a) (listof (listof a))))
  (cond [(empty? xs) (list)]
        [else (cons xs (suffixes (cdr xs)))]))

; (time (suffixes (range 200)))

(define (suf2 xs)
  (cond [(empty? xs) (list)]
        [else (cons xs (suffixes (cdr xs)))]))

(time (suf2 (range 200)))