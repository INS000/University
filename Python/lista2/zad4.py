import random
import string

tekst = "Podział peryklinalny inicjałów wrzecionowatych \
kambium charakteryzuje się ścianą podziałową inicjowaną \
w płaszczyźnie maksymalnej."

# https://polska-poezja.pl/lista-wierszy/203-jan-kochanowski-tren-vi
plik = open("tren6.txt", encoding='utf-8')
tekst2 = plik.read()

def uprosc_zdanie(tekst, dl_slowa, liczba_slow):
    tekst = tekst.split()
    wyn = []
    for s in tekst:
        s = s.strip(string.punctuation)
        if len(s) <= dl_slowa:
            wyn.append(s.lower())
    while len(wyn) > liczba_slow:
        i = random.randrange(len(wyn))
        wyn.pop(i)
    wyn[0] = wyn[0][0].upper() + wyn[0][1:]
    wyn[len(wyn) - 1] += '.'
    return ' '.join(wyn)

print(uprosc_zdanie(tekst, 10, 5))
print(uprosc_zdanie(tekst2, 10, 12))

