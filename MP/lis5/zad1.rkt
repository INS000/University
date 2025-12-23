#lang plait

(define (f1 a b) a)

(define (f2 f g x)
  (f x (g x)))

(define (ident x) x)
(define (pom h ii) (ii (h ii)))
(define (f3 x) (pom x ident))

(define (f4 f g) (lambda (x) (values (f x) (g x))))

(define (f5 f a)
  (type-case (Optionof 'a) (f a)
    [(none) '()]
    [(some n)
     (if (some? (f (fst n)))
         (list (snd n))
         '())]))

(define (pdp5 f a)
  (if (none? (f a))
      '()
      (if (none? (f (fst (some-v (f a))))) ;utwierdzanie sie ze a jest tego samego typu jak pierwszy element pary
          (list (snd (some-v (f a))))
          (list (snd (some-v (f a)))))))

