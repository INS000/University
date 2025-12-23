#lang racket

(provide
 dequeue?
 empty-dequeue
 nonempty-dequeue/c
 (contract-out
  [dequeue-empty?     (-> dequeue? boolean?)]
  [make-dequeue   (-> dequeue?)]
  [dequeue-push-front (-> dequeue? any/c any/c)]
  [dequeue-push-back  (-> dequeue? any/c any/c)]
  [dequeue-pop-front  (-> nonempty-dequeue/c any/c)]
  [dequeue-pop-back   (-> nonempty-dequeue/c any/c)]))

(struct dequeue-node ([prev #:mutable] [elem #:mutable] [next #:mutable]) #;#:transparent)
(struct dequeue ([front #:mutable] [back #:mutable]) #;#:transparent)

(define empty-dequeue (dequeue null null))

(define (dequeue-empty? q)
  (null? (dequeue-front q)))

(define nonempty-dequeue/c
  (and/c dequeue? (not/c dequeue-empty?)))

(define (make-dequeue)
  (dequeue null null))

(define (dequeue-push-front q x)
  (define new-elem (dequeue-node null x (dequeue-front q)))
  (if (dequeue-empty? q)
      (set-dequeue-back! q new-elem)
      (set-dequeue-node-prev! (dequeue-front q) new-elem))
  (set-dequeue-front! q new-elem))

(define (dequeue-push-back q x)
  (define new-elem (dequeue-node (dequeue-back q) x null))
  (if (dequeue-empty? q)
      (set-dequeue-front! q new-elem)
      (set-dequeue-node-next! (dequeue-back q) new-elem))
  (set-dequeue-back! q new-elem))

(define/contract (dequeue-pop-front q)
  (-> nonempty-dequeue/c any/c)
  (define pop-elem (dequeue-front q))
  (if (eq? pop-elem (dequeue-back q))
      (set-dequeue-back! q null)
      (set-dequeue-node-prev! (dequeue-node-next pop-elem) null))
  (set-dequeue-front! q (dequeue-node-next pop-elem))
  (dequeue-node-elem pop-elem))

(define/contract (dequeue-pop-back q)
  (-> nonempty-dequeue/c any/c)
  (define pop-elem (dequeue-back q))
  (if (eq? pop-elem (dequeue-front q))
      (set-dequeue-front! q null)
      (set-dequeue-node-next! (dequeue-node-prev pop-elem) null))
  (set-dequeue-back! q (dequeue-node-prev pop-elem))
  (dequeue-node-elem pop-elem))
