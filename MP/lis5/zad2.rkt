#lang plait
;zad2

( define ( apply f x ) ( f x ) )
;(('a -> 'b) 'a -> 'b)
;przyjmuje funkcje i argument funkcji i zwraca aplicje tej funkcji

( define ( compose f g ) ( lambda ( x ) ( f ( g x ) ) ) )
;(('a -> 'b) ('c -> 'a) -> ('c -> 'b))
;przyjmuje 2 funkcje i zwraca wynik ich zlozenia

( define ( flip f ) ( lambda ( x y ) ( f y x ) ) )
;(('a 'b -> 'c) -> ('b 'a -> 'c))
;retunrs the same function but reversely

( define ( curry f ) ( lambda ( x ) ( lambda ( y ) ( f x y ) ) ) )
;(('a 'b -> 'c) -> ('a -> ('b -> 'c)))



;zad3
(define a ( curry compose ))
;Pod curry ('a 'b -> 'c) -> ('a -> ('b -> 'c))
;podstawiamy compose ('a -> 'b) ('c -> 'a) -> ('c -> 'b)
;'a = ('x -> 'y)
;'b = ('z -> 'x)
;'c = ('z -> 'y)
;zatem zwracamy (('_a -> '_b) -> (('_c -> '_a) -> ('_c -> '_b)))

(define b (( curry compose ) ( curry compose ) ) )
;Pod obliczone wczesniej curry compose wstawiamy to samo
;('_a -> '_b) -> (('_c -> '_a) -> ('_c -> '_b))
;'_a = ('_x -> '_y)
;'_b = (('_z -> '_x) -> ('_z -> '_y))
;przeksztalcamy w (('_c -> ('_x -> '_y)) -> ('_c -> (('_z -> '_x) -> ('_z -> '_y))))
;zwracamy zatem (('_a -> ('_b -> '_c)) -> ('_a -> (('_d -> '_b) -> ('_d -> '_c))))

(define c (( curry compose ) ( curry apply ) ) )
;liczymy najpierw curry (('a 'b -> 'c) -> ('a -> ('b -> 'c)))
;podstawiamy apply (('a -> 'b) 'a -> 'b)
;'a = ('x -> 'y)
;'b = 'x
;'c = 'y
;Zatem zwracamy (('x -> 'y) -> ('x -> 'y))
;(('a -> 'b) -> ('a -> 'b))
;Teraz podstawiamy pod curry compose ('_a -> '_b) -> (('_c -> '_a) -> ('_c -> '_b))
;curry apply (('a -> 'b) -> ('a -> 'b))
;'a = ('_x -> '_y)
;'b = ('_x -> '_y)
;(('_a -> ('_b -> '_c)) -> ('_a -> ('_b -> '_c)))

(define d (( curry apply ) ( curry compose ) ) )
;Pod (('a -> 'b) -> ('a -> 'b)) podstawiamy ('_a -> '_b) -> (('_c -> '_a) -> ('_c -> '_b))
;'a = ('_x -> '_y)
;'b = (('_z -> '_x) -> ('_z -> '_y))
;(('_x -> '_y) -> (('_z -> '_x) -> ('_z -> '_y)))
;(('_a -> '_b) -> (('_c -> '_a) -> ('_c -> '_b)))

(define e ( compose curry flip ) )
;Pod compose (('a -> 'b) ('c -> 'a) -> ('c -> 'b)) za 1 arg wstawimy
;f : curry (('a 'b -> 'c) -> ('a -> ('b -> 'c))) a za 2 arg wstawimy
;g : flip (('a 'b -> 'c) -> ('b 'a -> 'c))
;
;f:
;'a = (x y -> z)
;'b = (x -> (y -> z))
;
;g:
;'c = (x' y' -> z')
;'a = (y' x' -> z')
;
;x = y', y = x', z = z'
;
;zatem
;('c -> 'b)
;((y x -> z) -> (x -> (y -> z))
;(('_a '_b -> '_c) -> ('_b -> ('_a -> '_c))


