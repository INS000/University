import itertools

def kryptarytm(slowo1, slowo2, wynik, operator):
    slowo1 = slowo1.upper()
    slowo2 = slowo2.upper()
    wynik = wynik.upper()
    litery = set(slowo1 + slowo2 + wynik)
    if len(litery) > 10:
        raise ValueError("Za duzo liter")
    for perm in itertools.permutations(range(10), len(litery)):
        dict_perm = dict(zip(litery, perm))
        if (dict_perm[slowo1[0]] == 0 and len(slowo1) > 1) or (dict_perm[slowo2[0]] == 0 and len(slowo2) > 1) or (dict_perm[wynik[0]] == 0 and len(wynik) > 1):
            continue
        licz1 = "".join(str(dict_perm[lit]) for lit in slowo1)
        licz2 = "".join(str(dict_perm[lit]) for lit in slowo2)
        wyn = "".join(str(dict_perm[lit]) for lit in wynik)

        licz1 = int(licz1)
        licz2 = int(licz2)
        wyn = int(wyn)
        if operator == "+" and licz1 + licz2 == wyn:
            yield (dict_perm, licz1, licz2, wyn)
        elif operator == "-" and licz1 - licz2 == wyn:
            yield (dict_perm, licz1, licz2, wyn)
        elif operator == "*" and licz1 * licz2 == wyn:
            yield (dict_perm, licz1, licz2, wyn)
        elif operator == "/" and licz1 / licz2 == wyn:
            yield (dict_perm, licz1, licz2, wyn)

def test(s1, s2, s3, op):
    s1 = s1.upper()
    s2 = s2.upper()
    s3 = s3.upper()
    print(f"Rozwiazanie dla {s1} {op} {s2} = {s3}:")
    for i in kryptarytm(s1, s2, s3, op):
        print(f"{i[1]} {op} {i[2]} = {i[3]} dla {i[0]}")
    print()

test("send", "more", "money", "+")
test("KYOTO", "OSAKA", "TOKYO", "+")
test("AH", "EH", "WALE", "*")
test("WHAT", "EH", "OAK", "/")
# test("WHALE", "FAKE", "OAKS", "-")


