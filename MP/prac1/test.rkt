#lang racket

(require racket/list)

(flatmap (lambda (x) (list (* x 2) (* x 3))) '(1 2 3))