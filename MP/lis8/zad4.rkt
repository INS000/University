#lang plait

(define-type Op
  (op-add) (op-mul) (op-sub) (op-div))

(define (parse-Op s)
  (let ([sym (s-exp->symbol s)])
  (cond
    [(equal? sym '+) (op-add)]
    [(equal? sym '-) (op-sub)]
    [(equal? sym '*) (op-mul)]
    [(equal? sym '/) (op-div)])))

(define (eval-Exp s)
  (cond
    [(s-exp-number? s) (s-exp->number s)]
    [(s-exp-list? s)
     (let* ([xs (s-exp->list s)]
     [op (parse-Op (first xs))])
     (type-case Op op
     [(op-add) (+ (eval-Exp (second xs)) (eval-Exp (third xs)))]
     [(op-sub) (- (eval-Exp (second xs)) (eval-Exp (third xs)))]
     [(op-mul) (* (eval-Exp (second xs)) (eval-Exp (third xs)))]
     [(op-div) (/ (eval-Exp (second xs)) (eval-Exp (third xs)))]))]))

