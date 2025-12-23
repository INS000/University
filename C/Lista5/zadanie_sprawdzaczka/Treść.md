## Prostopadłościan o zadanej przekątnej
W pierwszym i jedynym wierszu standardowego wejścia podana będzie jedna dodatnia liczba naturalna d ≤ 100000. Napisz program, który ją wczyta, a następnie rozstrzygnie, czy istnieje prostopadłościan, którego krawędzie są całkowitej długości, a przekątna – długości d. Jedyny wiersz wyjścia powinien zawierać:

* napis "BRAK", jeśli taki prostopadłościan nie istnieje;
* trzy oddzielone spacjami liczby całkowite w kolejności nierosnącej, stanowiące długości krawędzi takiego prostopadłościanu, jeśli istnieje. Jeśli istnieje więcej niż jeden taki prostopadłościan, podaj długości krawędzi tego z nich, który "najbardziej przypomina sześcian", tj. którego najkrótsza krawędź jest możliwie najdłuższa ("remisy" "rozstrzyga" długość pośredniej krawędzi).

**Uwaga:** w tym zadaniu w sprawdzaczce włączona jest dodatkowo flaga kompilacji -O3, więc używaj jej również przy lokalnym testowaniu swojego programu. W szczególności w połączeniu z innymi flagami konieczne może być przypisanie wartości zwróconej przez funkcję scanf do jakiejś zmiennej (którą później można zignorować i nadpisać – jak zwykle na sprawdzaczce poprawność wejścia jest zagwarantowana).

### Przykłady danych wejściowych i wyjściowych
Przykładowe wejście nr 1:

16

Poprawne wyjście dla przykładowego wejścia nr 1:

BRAK

Przykładowe wejście nr 2:

17

Poprawne wyjście dla przykładowego wejścia nr 2:

12 9 8
