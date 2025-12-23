### LISTA 3: Najdłuższy cykl w permutacji

Permutacja n-elementowego zbioru {1, 2, …, n} to wzajemnie jednoznaczne przekształcenie tego zbioru na siebie (bijekcja). Liczba wszystkich permutacji n-elementowego zbioru wynosi n!. Rozważmy dla przykładu pewną permutację σ zbioru {1, 2, 3, 4, 5, 6, 7}, którą zapiszemy w postaci tabelarycznej:

|  i  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |
| --- | --- | --- | --- | --- | --- | --- | --- |
| σ(i)|  4  |  5  |  3  |  7  |  2  |  1  |  6  |


Często permutacje zapisuje się w formie skróconej w postaci ciągu wartości przypisanych kolejnym liczbom (drugi wiersz tabeli), co dla powyższego przykładu wygląda tak:

4, 5, 3, 7, 2, 1, 6

Oznacza to, że permutacja dokonuje następujących przekształceń:

1→4, 2→5, 3→3, 4→7, 5→2, 6→1, 7→6

Porządkując te przekształcenia otrzymamy następujące cykle:

1→4, 4→7, 7→6, 6→1; 2→5, 5→2; 3→3

Widać więc, że permutację można przedstawić w postaci rozłącznych cykli:

(1, 4, 7, 6); (2, 5); (3)

#### Zadanie

Napisz program znajdujący długość najdłuższego cyklu zadanej permutacji.

#### Wejście

W pierwszym wierszu znajduje się liczba naturalna n, nie większa od 1000000 – jest to długość permutacji. W drugim wierszu zapisana jest permutacja n-elementowa (złożona z liczb 1, 2, …, n) w postaci skróconej, tj. liczb z "drugiego wiersza tabeli", oddzielonych od siebie spacjami (bez przecinków).

#### Wyjście

W jedynym wierszu wyjścia znajduje się liczba naturalna równa długości najdłuższego cyklu w zadanej permutacji.

#### Przykład

Dla danych wejściowych

9

8 2 1 6 7 9 4 3 5

poprawną odpowiedzią jest

5

ponieważ najdłuższy cykl to (4, 6, 9, 5, 7).
