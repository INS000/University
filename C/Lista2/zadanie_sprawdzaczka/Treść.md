## Szyszki
Zadanie polega na symulacji życia lasu. Na prostokątnym obszarze zasadzone są drzewa na różnych etapach wzrostu, oznaczonych liczbami od 1 do 9.

O różnych porach dnia słońce pada na las z różnych stron: rano od wschodu (z prawej), w południe od południa (z dołu) i wieczorem od zachodu (z lewej). Drzewa rzucają wtedy cień: drzewo wzrostu X rzuca cień na X pól w linii prostej od drzewa, zgodnie z kierunkiem padania słońca. Wszystkie drzewa, które znajdują się na zacienionych polach są wtedy w cieniu.

O każdej porze dnia, każde drzewo, które nie jest w cieniu:

* zwiększa swój wzrost o 1, jeśli nie osiągnęło jeszcze maksymalnego wzrostu 9;
* albo produkuje szyszkę, jeśli jest już wzrostu 9.

Drzewa w danej porze dnia rosną równocześnie, czyli rzucane cienie się nie zmieniają w jej trakcie.

Napisz program, który oblicza ile w sumie będzie szyszek po podanej liczbie dni.

### Wejście
W pierwszym wierszu trzy liczby naturalne: szerokość w, wysokość h, liczba dni d. Ograniczenia: 1 ≤ w, h ≤ 100, 1 ≤ d ≤ 10^14.

W kolejnych h wierszach podany jest opis obszaru: każdy wiersz zawiera w znaków, gdzie znak '.' oznacza puste pole, a znaki od '1' do '9' oznaczają drzewo określonego przez tę cyfrę wzrostu.

### Wyjście
Liczba zebranych szyszek po d dniach.

### Przykład A
```
3 2 4
2.1
.1.
```

Pierwszego dnia rano i w południe żadne drzewo nie jest w cieniu, więc wszystkie wzrastają. Wieczorem drzewo w lewym górnym rogu rzuca cień na drzewo po prawej, które wtedy nie rośnie. Po pierwszym dniu sytuacja wygląda więc tak:
```
5.3
.4.
```
Po drugim dniu:
```
7.5
.7.
```
Po trzecim dniu:
```
9.7
.9.
```
Dostajemy wtedy też 1 szyszkę wieczorem.

Po czwartym dniu:
```
9.9
.9.
```
I w tym dniu dostajemy 5 szyszek (rano 1, w południe 2, wieczorem 2).

Wynik:

6

### Przykład B
```
3 3 10
.2.
418
.6.
```
Wynik:

74

Drzewo w środku pozostaje zawsze zacienione, więc nie rośnie.

Sytuacja po 10. dniu:
```
.9.
919
.9.
```
### Podpowiedź techniczna
Opis obszaru najłatwiej wczytać używając scanf. Spacja w argumencie powoduje pominięcie białych znaków, w szczególności końców linii.
``` c
for (int y = 0; y < h; y++)
  for (int x = 0; x < w; x++) {
    char c;
    if (scanf(" %c", &c) != 1) return 1;// Wczytuje kolejny niebiały znak
    if (c >= '1' && c <= '9') {
      // Drzewo wzrostu c - '0'
    } else {
      // Puste pole
    }
  }
```
### Uwaga o działaniu sprawdzaczki
Komunikat "Testowanie zostało przerwane z powodu błędu" oznacza błąd wykonania (np. segmentation fault) lub przekroczenie limitu czasu. Wówczas testowanie jest przerywane i nie są pokazywane wyniki dla kolejnych testów.
