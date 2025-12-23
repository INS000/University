#lang racket
(require data/heap)
(provide sim? wire?
         (contract-out
          [make-sim        (-> sim?)]
          [sim-wait!       (-> sim? positive? void?)]
          [sim-time        (-> sim? real?)]
          [sim-add-action! (-> sim? positive? (-> any/c) void?)]

          [make-wire       (-> sim? wire?)]
          [wire-on-change! (-> wire? (-> any/c) void?)]
          [wire-value      (-> wire? boolean?)]
          [wire-set!       (-> wire? boolean? void?)]

          [bus-value (-> (listof wire?) natural?)]
          [bus-set!  (-> (listof wire?) natural? void?)]

          [gate-not  (-> wire? wire? void?)]
          [gate-and  (-> wire? wire? wire? void?)]
          [gate-nand (-> wire? wire? wire? void?)]
          [gate-or   (-> wire? wire? wire? void?)]
          [gate-nor  (-> wire? wire? wire? void?)]
          [gate-xor  (-> wire? wire? wire? void?)]

          [wire-not  (-> wire? wire?)]
          [wire-and  (-> wire? wire? wire?)]
          [wire-nand (-> wire? wire? wire?)]
          [wire-or   (-> wire? wire? wire?)]
          [wire-nor  (-> wire? wire? wire?)]
          [wire-xor  (-> wire? wire? wire?)]

          [flip-flop (-> wire? wire? wire? void?)]))

(define-struct action (time fun))

(define (lowact ac1 ac2)
  (<= (action-time ac1) (action-time ac2)))

(struct sim ([time #:mutable] [act-que #:mutable]))

(define (make-sim)
  (sim 0 (make-heap lowact)))

(define (sim-wait! sym timer)
  (if (and (> (heap-count (sim-act-que sym)) 0) (>= timer (- (action-time (heap-min (sim-act-que sym))) (sim-time sym))))
      (let ([firac (heap-min (sim-act-que sym))])
        (begin (let ([czas (- (+ timer (sim-time sym)) (action-time firac))])
                 ((action-fun firac))
               (set-sim-time! sym (action-time firac))
               (heap-remove-min! (sim-act-que sym))
               (sim-wait! sym czas))))
      (set-sim-time! sym (+ timer (sim-time sym)))))

(define (sim-add-action! simu delaj act)
  (heap-add! (sim-act-que simu) (action (+ (sim-time simu) delaj) act)))

(struct wire ([value #:mutable] [action #:mutable] sim))

(define (make-wire sym)
  (wire #f (list) sym))

(define (wire-on-change! wir act)
  (begin (set-wire-action! wir (cons act (wire-action wir)))
         (act)))

(define (wire-set! kab boli)
  (if (not (equal? boli (wire-value kab)))
      (begin (set-wire-value! kab boli)
         (map (lambda (x) (x)) (wire-action kab))
         (void))
      (void)))

(define (bus-set! wires value)
  (match wires
    ['() (void)]
    [(cons w wires)
     (begin
       (wire-set! w (= (modulo value 2) 1))
       (bus-set! wires (quotient value 2)))]))

(define (bus-value ws)
  (foldr (lambda (w value) (+ (if (wire-value w) 1 0) (* 2 value)))
         0
         ws))

(define (gate-not wirout wirin)
  (define (not-action)
    (sim-add-action! (wire-sim wirout) 1 (lambda () (wire-set! wirout (not (wire-value wirin))))))
  (wire-on-change! wirin not-action))

(define (gate-and wirout wirin1 wirin2)
  (define (and-action)
    (sim-add-action! (wire-sim wirout) 1 (lambda () (wire-set! wirout (and (wire-value wirin1) (wire-value wirin2))))))
  (begin (wire-on-change! wirin1 and-action)
  (wire-on-change! wirin2 and-action)))

(define (gate-nand wirout wirin1 wirin2)
  (define (nand-action)
    (sim-add-action! (wire-sim wirout) 1 (lambda () (wire-set! wirout (nand (wire-value wirin1) (wire-value wirin2))))))
  (begin (wire-on-change! wirin1 nand-action)
  (wire-on-change! wirin2 nand-action)))

(define (gate-or wirout wirin1 wirin2)
  (define (or-action)
    (sim-add-action! (wire-sim wirout) 1 (lambda () (wire-set! wirout (or (wire-value wirin1) (wire-value wirin2))))))
  (begin (wire-on-change! wirin1 or-action)
  (wire-on-change! wirin2 or-action)))

(define (gate-nor wirout wirin1 wirin2)
  (define (nor-action)
    (sim-add-action! (wire-sim wirout) 1 (lambda () (wire-set! wirout (nor (wire-value wirin1) (wire-value wirin2))))))
  (begin (wire-on-change! wirin1 nor-action)
  (wire-on-change! wirin2 nor-action)))

(define (gate-xor wirout wirin1 wirin2)
  (define (xor-action)
    (sim-add-action! (wire-sim wirout) 2 (lambda () (wire-set! wirout (xor (wire-value wirin1) (wire-value wirin2))))))
  (begin (wire-on-change! wirin1 xor-action)
  (wire-on-change! wirin2 xor-action)))

(define (wire-not wirin)
  (define wirout
    (make-wire (wire-sim wirin)))
  (begin (gate-not wirout wirin)
  wirout))

(define (wire-and wirin1 wirin2)
  (define wirout
    (make-wire (wire-sim wirin1)))
  (begin (gate-and wirout wirin1 wirin2)
  wirout))

(define (wire-nand wirin1 wirin2)
  (define wirout
    (make-wire (wire-sim wirin1)))
  (begin (gate-nand wirout wirin1 wirin2)
  wirout))

(define (wire-or wirin1 wirin2)
  (define wirout
    (make-wire (wire-sim wirin1)))
  (begin (gate-or wirout wirin1 wirin2)
  wirout))

(define (wire-nor wirin1 wirin2)
  (define wirout
    (make-wire (wire-sim wirin1)))
  (begin (gate-nor wirout wirin1 wirin2)
  wirout))

(define (wire-xor wirin1 wirin2)
  (define wirout
    (make-wire (wire-sim wirin1)))
  (begin (gate-xor wirout wirin1 wirin2)
  wirout))

(define (flip-flop out clk data)
  (define sim (wire-sim data))
  (define w1  (make-wire sim))
  (define w2  (make-wire sim))
  (define w3  (wire-nand (wire-and w1 clk) w2))
  (gate-nand w1 clk (wire-nand w2 w1))
  (gate-nand w2 w3 data)
  (gate-nand out w1 (wire-nand out w3)))
