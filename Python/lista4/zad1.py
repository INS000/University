class Wyrazenie:
    def oblicz(self):
        pass

    def __str__(self):
        pass

    def __add__(self, other):
        if isinstance(other, Wyrazenie):
            return Dodaj(self, Stala(other))
        raise myTypeError(other)

    def __mul__(self, other):
        if isinstance(other, Wyrazenie):
            return Razy(self, Stala(other))
        raise myTypeError(other)

    def pochodna(self, zmienna):
        pass


class Stala(Wyrazenie):
    def __init__(self, wartosc):
        self.wartosc = wartosc

    def oblicz(self, zmienne):
        return self.wartosc

    def __str__(self):
        return str(self.wartosc)

    def pochodna(self, zmienna):
        return Stala(0)

class Zmienna(Wyrazenie):
    def __init__(self, nazwa):
        self.nazwa = nazwa

    def oblicz(self, zmienne):
        if self.nazwa in zmienne:
            return zmienne[self.nazwa]
        raise myVariableError(self.nazwa)

    def __str__(self):
        return self.nazwa

    def pochodna(self, zmienna):
        if self.nazwa == zmienna:
            return Stala(1)
        return Stala(0)

class Dodaj(Wyrazenie):
    def __init__(self, a, b):
        if not isinstance(a, Wyrazenie):
            raise myTypeError(a)
        if not isinstance(b, Wyrazenie):
            raise myTypeError(b)
        self.a = a
        self.b = b

    def oblicz(self, zmienne):
        return self.a.oblicz(zmienne) + self.b.oblicz(zmienne)

    def __str__(self):
        return f"({self.a} + {self.b})"

    def pochodna(self, zmienna):
        return Dodaj(self.a.pochodna(zmienna), self.b.pochodna(zmienna))

class Razy(Wyrazenie):
    def __init__(self, a, b):
        if not isinstance(a, Wyrazenie):
            raise myTypeError(a)
        if not isinstance(b, Wyrazenie):
            raise myTypeError(b)
        self.a = a
        self.b = b

    def oblicz(self, zmienne):
        return self.a.oblicz(zmienne) * self.b.oblicz(zmienne)

    def __str__(self):
        return f"({self.a} * {self.b})"

    def pochodna(self, zmienna):
        return Dodaj(Razy(self.a.pochodna(zmienna), self.b), Razy(self.a, self.b.pochodna(zmienna)))

class Odejmij(Wyrazenie):
    def __init__(self, a, b):
        if not isinstance(a, Wyrazenie):
            raise myTypeError(a)
        if not isinstance(b, Wyrazenie):
            raise myTypeError(b)
        self.a = a
        self.b = b

    def oblicz(self, zmienne):
        return self.a.oblicz(zmienne) - self.b.oblicz(zmienne)

    def __str__(self):
        return f"({self.a} - {self.b})"

    def pochodna(self, zmienna):
        return Odejmij(self.a.pochodna(zmienna), self.b.pochodna(zmienna))

class Podziel(Wyrazenie):
    def __init__(self, a, b):
        if not isinstance(a, Wyrazenie):
            raise myTypeError(a)
        if not isinstance(b, Wyrazenie):
            raise myTypeError(b)
        self.a = a
        self.b = b

    def oblicz(self, zmienne):
        if self.b.oblicz(zmienne) == 0:
            raise myDivZeroError()
        return self.a.oblicz(zmienne) / self.b.oblicz(zmienne)

    def __str__(self):
        return f"({self.a} / {self.b})"

    def pochodna(self, zmienna):
        return Podziel(Odejmij(Razy(self.a.pochodna(zmienna), self.b), Razy(self.a, self.b.pochodna(zmienna))), Razy(self.b, self.b))

class myException(Exception):
    def __str__(self):
        return str(self.args[0])

class myDivZeroError(myException):
    def __init__(self):
        super().__init__("Dzielenie przez zero jest niemożliwe")

class myVariableError(myException):
    def __init__(self, zmienna):
        super().__init__(f"Brak wartości zmiennej {zmienna}")

class myTypeError(myException):
    def __init__(self, wyrazenie):
        super().__init__(f"{wyrazenie} nie jest obiektem klasy Wyrazenie")


zmienne = {"x": 3, "y": 2}

wyrazenie_funkcja = Razy(Dodaj(Zmienna("x"), Stala(2)), Zmienna("x")) # x^2 + 2x
wyrazenie_dziel_zero = Podziel(Stala(1), Stala(0))
wyrazenie_z = Dodaj(Zmienna("x"), Zmienna("z")) # x + y


print("Wyrażenie:", wyrazenie_dziel_zero) # 1 / 0
try:
    print(wyrazenie_dziel_zero.oblicz(zmienne)) # 12
except myException as e:
    print(e)


print("Wyrażenie:", wyrazenie_funkcja) # (x + 2) * x
try:
    print("Wartość funkcji:", wyrazenie_funkcja.oblicz(zmienne)) # 12
except myException as e:
    print(e)


print("Wyrażenie:", wyrazenie_funkcja) # (x + 2) * x
try:
    print("Pochodna:", wyrazenie_funkcja.pochodna("x")) # 2x + 2
except myException as e:
    print(e)

print("wyrazenie:", wyrazenie_z.__str__())
try:
    print("wyrazenie z z:", wyrazenie_z.oblicz(zmienne))
except myException as e:
    print(e)

zmienne = {"x": 3, "y": 2, "z": 1}

try:
    print("wyrazenie z z:", wyrazenie_z.oblicz(zmienne)) # 4
except myException as e:
    print(e)

try:
    a = Dodaj(1, 2)
except myException as e:
    print(e)


a = Razy(Stala(1), Zmienna("x"))
b = Stala(2)

try:
    print(a + b)
except myException as e:
    print(e)


try:
    print(a * b)
except myException as e:
    print(e)
