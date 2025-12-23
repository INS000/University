## Identyfikatory
Danych jest n > 2 identyfikatorów. Każdy identyfikator składa się z k > 2 liter. Rozważmy identyfikator Idp = (x_0, x_1, …, x_k-1). Jeśli litera xr na pozycji r-tej różni się od wszystkich liter na r-tej pozycji dla wszystkich pozostałych identyfikatorów to mówimy, że r-ta pozycja w tym identyfikatorze jest unikatowa. Unikatowość identyfikatora to liczba unikatowych pozycji w identyfikatorze. Napisz program, który wskaże najbardziej unikatowy identyfikator.

#### Wejście:

W pierwszym wierszu podane są dwie liczby naturalne: 3 ≤ n, k ≤ 1000. Następnie w kolejnych n liniach podane są k-literowe identyfikatory złożone z małych liter alfabetu angielskiego (26 liter od a do z).

#### Wyjście:

W pierwszym wierszu wyjściowym należy wypisać najbardziej unikatowy identyfikator a w drugim unikatowość tego identyfikatora (liczbę unikatowych pozycji). Jeśli jest kilka identyfikatorów o maksymalnej unikatowości, to wypisz pierwszy z nich.

#### Przykład 1:

Dla danych wejściowych:
```
4 5
abcba
acbcb
cbcac
cbaca
```
poprawną odpowiedzią będzie:
```
acbcb
3
```
ponieważ w tym identyfikatorze są aż 3 unikatowe pozycje 1, 2 i 4 odpowiadające literom _cb_b.

#### Przykład 2:

Dla danych wejściowych:
```
3 6
xyyxyx
yxyxxx
yyxyxx
```

poprawną odpowiedzią będzie:
```
xyyxyx
2
```
ponieważ w tym identyfikatorze są 2 unikatowe pozycje 0 i 4 odpowiadające literom x___y_ (jest też inny identyfikator z 2 unikatowymi pozycjami yyxyxx, ale jest on na dalszej pozycji).
