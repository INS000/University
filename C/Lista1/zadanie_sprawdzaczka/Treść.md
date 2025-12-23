## Przedstawienie w układzie liczb Fibonacciego
**Liczby Fibonacciego** to ciąg zdefiniowany taką zależnością rekurencyjną (w niektórych źródłach podaje się czasem inne indeksy dla początkowych wyrazów, ale tu umawiamy się na poniższe):

F_0 = 0

F_1 = 1

F_{n+2} = F_{n+1} + F_n dla n ≥ 0

przy czym oczywiście lepiej wyliczać go iteracyjnie, a nie rekurencyjnie.

**Przedstawienie** liczby naturalnej n **w układzie liczb Fibonacciego** to taki ciąg a_2, a_3, …, a_k (zauważ brak a_0, a_1) składający się z zer i jedynek, w którym nie występują dwie jedynki pod rząd, a_k = 1, oraz

a_2 F_2 + a_3 F_3 + … + a_k F_k = n.

W pierwszym i jedynym wierszu standardowego wejścia podana będzie jedna dodatnia liczba naturalna n ≤ 2×10^9. Napisz program, który ją wczyta, oraz wypisze jej przedstawienie w układzie liczb Fibonacciego począwszy od najbardziej znaczącego wyrazu, tj. od a_k do a_2. W jedynym wierszu standardowego wyjścia powinny znajdować się tylko jedynki i zera, **bez spacji.**

### Przykłady danych wejściowych i wyjściowych
Przykładowe wejście nr 1:

4

Poprawne wyjście dla przykładowego wejścia nr 1:

101

Przykładowe wejście nr 2:

5

Poprawne wyjście dla przykładowego wejścia nr 2:

1000

Przykładowe wejście nr 3:

256

Poprawne wyjście dla przykładowego wejścia nr 3:

100001000010

### Uwagi i wskazówki
Program powinien czytać jedną liczbę całkowitą bez znaku ze standardowego wejścia używając funkcji scanf, np. scanf("%u", &nazwa_zmiennej).

Każda liczba naturalna ma jednoznaczne przedstawienie w układzie liczb Fibonacciego, które można wyliczać zachłannie. (Będziesz musiał/-a to udowodnić dopiero na matematyce dyskretnej, tutaj wystarczy z tego skorzystać.)
