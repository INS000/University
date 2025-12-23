Liczba bezkwadratowa to taka dodatnia liczba naturalna, która nie dzieli się (bez reszty) przez kwadrat jakiejś liczby naturalnej większej od 1. Do liczb bezkwadratowych należy 10, bo wśród jej dzielników (1, 2, 5, 10) jedynym kwadratem jest właśnie 1, zaś nie należą do nich 18 (podzielne przez 9), 48 (podzielne przez 16) czy 49 (podzielne przez 49).

W pierwszym i jedynym wierszu standardowego wejścia podana będzie jedna dodatnia liczba naturalna A mniejsza niż 10^9 (możesz założyć, że wejście jest zgodne z tą specyfikacją). Napisz program, który ją wczyta, oraz znajdzie najmniejszą liczbę bezkwadratową należącą do przedziału [A, A + 1000] (obustronnie domkniętego). W jedynym wierszu wypisywanym przez program na standardowe wyjście powinna znaleźć się ta liczba, bądź słowo "BRAK", jeśli takiej liczby nie ma. (Nie wypisuj żadnych dodatkowych informacji, wyjaśnień itp.)

### Przykłady danych wejściowych i wyjściowych
Przykładowe wejście nr 1:

80

Poprawne wyjście dla przykładowego wejścia nr 1:

82

Przykładowe wejście nr 2:

82

Poprawne wyjście dla przykładowego wejścia nr 2:

82

Przykładowe wejście nr 3:

12345678

Poprawne wyjście dla przykładowego wejścia nr 3:

12345679

### Uwagi i wskazówki
Program powinien czytać jedną liczbę całkowitą ze standardowego wejścia używając funkcji scanf, np. scanf("%d", &nazwa_zmiennej).

Liczba, która dzieli się przez kwadrat liczby naturalnej > 1, dzieli się też przez kwadrat jakiejś liczby pierwszej i wystarczy sprawdzać tylko takie podzielniki. Można stosować różne usprawnienia inspirowane czy wręcz wprost pojawiające się w programie z wykładu o rozkładzie liczby na czynniki pierwsze.

Liczb bezkwadratowych jest dużo i są rozłożone stosunkowo równomiernie, więc wyjście "BRAK" dla poprawnego wejścia raczej nie ma się szans pojawić.
