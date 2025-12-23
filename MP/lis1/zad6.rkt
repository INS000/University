#lang racket

(define ifCond (= 3 3))

(define ifTrue "TRUE")

(define ifFalse "FALSE")

(define if1 (or (and ifCond ifTrue) ifFalse))