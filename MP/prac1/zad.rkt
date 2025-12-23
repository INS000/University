#lang racket

(require racket/list)

(provide (struct-out column-info)
         (struct-out table)
         (struct-out and-f)
         (struct-out or-f)
         (struct-out not-f)
         (struct-out eq-f)
         (struct-out eq2-f)
         (struct-out lt-f)
         table-insert
         table-project
         table-sort
         table-select
         table-rename
         table-cross-join
         table-natural-join)


(define-struct column-info (name type) #:transparent)

(define-struct table (schema rows) #:transparent)

(define cities
  (table
   (list (column-info 'city    'string)
         (column-info 'country 'string)
         (column-info 'area    'number)
         (column-info 'capital 'boolean))
   (list (list "Wrocław" "Poland"  293 #f)
         (list "Warsaw"  "Poland"  517 #t)
         (list "Poznań"  "Poland"  262 #f)
         (list "Berlin"  "Germany" 892 #t)
         (list "Munich"  "Germany" 310 #f)
         (list "Paris"   "France"  105 #t)
         (list "Rennes"  "France"   50 #f))))

(define countries
  (table
   (list (column-info 'country 'string)
         (column-info 'population 'number))
   (list (list "Poland" 38)
         (list "Germany" 83)
         (list "France" 67)
         (list "Spain" 47))))

(define (empty-table columns) (table columns '()))

; Wstawianie

(define (type_to s)
  (cond [(string? s) 'string]
        [(number? s) 'number]
        [(symbol? s) 'symbol]
        [(boolean? s) 'boolean]))

(define (same_type row schem)
  (if (empty? row) #t
      (if (not (equal? (type_to (car row)) (car schem))) #f
         (same_type (cdr row) (cdr schem)))))

(define (table-insert row tab)
  (if (not (or (= (length (table-schema tab)) (length (table-schema tab))) (same_type row (table-schema tab)))) (error "Bledny wiersz")
      (table (table-schema tab) (cons row (table-rows tab)))))


; Projekcja

(define (filtered-scheme cols schema) (filter (lambda (col) (member (column-info-name col) cols)) schema))

(define (flat-names scheme)
  (map (lambda (row) (column-info-name row)) scheme))

;(define (get-col-info name scheme)
;  (if (equal? (column-info-name (car scheme)) name) (car scheme)
;      (get-col-info name (cdr scheme))))

;(define (filtered-scheme cols scheme)
;  (if (empty? cols) (list)
;      (if (member (car cols) (flat-names scheme)) (cons (get-col-info (car cols) scheme) (filtered-scheme (cdr cols) scheme))
 ;         (filtered-scheme (cdr cols) scheme))))

(define (get-indexes a b)
  (if (empty? a) (list)
     (cons (index-of b (car a)) (get-indexes (cdr a) b))))

(define (filtered-rows cols tab)
  (map (lambda (row) (map (lambda (index) (list-ref row index)) (sort (get-indexes cols (flat-names (table-schema tab))) <))) (table-rows tab)))

(define (table-project cols tab)
 (table
   (filtered-scheme cols (table-schema tab))
   (filtered-rows cols tab)))

; Zmiana nazwy

(define (change-info name nname scheme)
  (cond [(empty? scheme) (list)]
        [(equal? (column-info-name (car scheme)) name) (cons (column-info nname (column-info-type (car scheme))) (change-info name nname (cdr scheme)))]
        [else (cons (car scheme) (change-info name nname (cdr scheme)))]))

(define (table-rename col ncol tab)
  (table
   (change-info col ncol (table-schema tab))
   (table-rows tab))
  )

; Selekcja

(define-struct and-f (l r))
(define-struct or-f (l r))
(define-struct not-f (e))
(define-struct eq-f (name val))
(define-struct eq2-f (name name2))
(define-struct lt-f (name val))

(define (better< a b)
  (cond [(and (number? a) (number? b)) (< a b)]
        [(and (string? a) (string? b)) (string<? a b)]
        [(and (symbol? a) (symbol? b)) (symbol<? a b)]
        [(and (boolean? a) (boolean? b)) (and (not a) b)]))

;(define (better<= a b)
;  (cond [(and (number? a) (number? b)) (<= a b)]
;        [(and (string? a) (string? b)) (string<=? a b)]
;        [(and (symbol? a) (symbol? b)) (string<=? (symbol->string a) b)]
;        [(and (boolean? a) (boolean? b)) (or (not a) b)]))

(define (eval form row scheme)
  (cond [(and-f? form) (and (eval (and-f-l form) row scheme) (eval (and-f-r form) row scheme))]
        [(or-f? form) (or (eval (or-f-l form) row scheme) (eval (or-f-r form) row scheme))]
        [(not-f? form) (not (eval (not-f-e form) row scheme))]
        [(eq-f? form) (equal? (eq-f-val form) (list-ref row (index-of (flat-names scheme) (eq-f-name form))))]
        [(eq2-f? form) (equal? (list-ref row (index-of (flat-names scheme) (eq2-f-name form))) (list-ref row (index-of (flat-names scheme) (eq2-f-name2 form))))]
        [(lt-f? form) (better< (list-ref row (index-of (flat-names scheme) (lt-f-name form))) (lt-f-val form))]
        [else form]))

(define (select-rows form rows scheme)
  (cond [(empty? rows) (list)]
        [(eval form (car rows) scheme) (cons (car rows) (select-rows form (cdr rows) scheme))]
        [else (select-rows form (cdr rows) scheme)]))

(define (table-select form tab)
  (table
   (table-schema tab)
   (select-rows form (table-rows tab) (table-schema tab)))
  )


; Sortowanie

(define (cell name row scheme)
  (list-ref row (index-of (flat-names scheme) name)))

(define (compare row row2 cols tab)
 (cond [(better< (cell (car cols) row (table-schema tab)) (cell (car cols) row2 (table-schema tab))) #t]
       [(and (equal? (cell (car cols) row (table-schema tab)) (cell (car cols) row2 (table-schema tab))) (empty? (cdr cols))) #f]
       [(equal? (cell (car cols) row (table-schema tab)) (cell (car cols) row2 (table-schema tab))) (compare row row2 (cdr cols) tab)]
       [else #f]))

(define (insert n xs cols tab)
  (if (null? xs) (list n)
      (if (compare n (car xs) cols tab) (cons n xs)
          (cons (car xs) (insert n (cdr xs) cols tab)))))

(define (sorted-rows tab cols)
   (define (it xs ys)
    (if (null? xs)
        ys
        (it (cdr xs) (insert (car xs) ys cols tab))))
  (it (table-rows tab) null))

(define (table-sort cols tab)
  (table
   (table-schema tab)
   (sorted-rows tab cols))
  )


; Złączenie kartezjańskie

(define (table-cross-join tab1 tab2)
  (table
   (append (table-schema tab1) (table-schema tab2))
   (map (lambda (x) (append (first x) (second x))) (cartesian-product (table-rows tab1) (table-rows tab2))))
  )

; Złączenie

(define (compare row row2 cols tab)
 (cond [(better< (cell (car cols) row (table-schema tab)) (cell (car cols) row2 (table-schema tab))) #t]
       [(and (equal? (cell (car cols) row (table-schema tab)) (cell (car cols) row2 (table-schema tab))) (empty? (cdr cols))) #f]
       [(equal? (cell (car cols) row (table-schema tab)) (cell (car cols) row2 (table-schema tab))) (compare row row2 (cdr cols) tab)]
       [else #f]))

(define (in-both flat1 flat2)
  (cond [(empty? flat2) (list)]
        [(member (car flat2) flat1) (cons (car flat2) (in-both flat1 (cdr flat2)))]
        [else (in-both flat1 (cdr flat2))])
  )

(define (eq-cols cols schem1 schem2 row1 row2)
  (cond [(empty? cols) #t]
        [(equal? (list-ref row1 (index-of (flat-names schem1) (car cols))) (list-ref row2 (index-of (flat-names schem2) (car cols)))) (eq-cols (cdr cols) schem1 schem2 row1 row2)]
        [else #f]))

(define (nat-rows col))






