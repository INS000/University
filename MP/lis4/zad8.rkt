#lang racket

(define-struct ord (val priority) #:transparent)
(define-struct hleaf () )
(define-struct hnode (elem rank l r) #:transparent)



(define (hord? p h)
   (or (hleaf? h)
       (<= p (ord-priority (hnode-elem h) ) ) ) )

(define (rank h)
   (if (hleaf? h)
       0
       (hnode-rank h) ) )

(define (heap? h)
   (or (hleaf? h)
       (and (hnode? h)
            (heap? (hnode-l h) )
            (heap? (hnode-r h) )
            (<= (rank (hnode-r h) )
                (rank (hnode-l h) ) )
            (= (hnode-rank h) (+ 1 (hnode-rank ( hnode-r h) ) ) )
            (hord? (ord-priority (hnode-elem h) )
                   (hnode-l h) )
            (hord? (ord-priority (hnode-elem h) )
                   (hnode-r h) ) ) ) )

(define (make-node elem heap-a heap-b)
  (if (< (rank heap-a) (rank heap-b)) (hnode elem (+ 1 (rank heap-a) heap-b heap-a))
      (hnode elem (+ 1 (rank heap-b) heap-a heap-b))))


(define (heap-merge h1 h2)
  (cond [(hleaf? h1) h2]
        [(hleaf? h2) h1]
        [(< (ord-priority (hnode-elem h1)) (ord-priority (hnode-elem h2)))
         (let [(e (hnode-elem h1)) (hl (hnode-l h1)) (hr (hnode-r h1)) (h h2)]
           (make-node e hl (heap-merge hr h)))]
        [else
          (let [(e (hnode-elem h2)) (hl (hnode-l h2)) (hr (hnode-r h2)) (h h1)]
            (make-node e hl (heap-merge hr h)))]))

(define empty-pq (hleaf))

(define (pq-insert elem h)
  (heap-merge (make-node elem (hleaf) (hleaf)) h))

(define (pq-pop h)
  (heap-merge (hnode-l h) (hnode-r h)))

(define (pq-min h)
  (ord-val (hnode-elem h)))

(define (pq-empty h)
  (hleaf? h))

(define (list->leftist xs)
  (foldl (λ(x xx) (pq-insert (ord x (* -1 x)) xx)) (hleaf) xs))

(define (leftist->list h xs)
  (if (hleaf? h) xs
      (let* [(min (pq-min h)) (hh (pq-pop h))]
        (leftist->list hh (cons min xs)))))

(define (pqsort xs)
  (leftist->list (list->leftist xs) '()))