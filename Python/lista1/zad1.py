def vat_faktura(lista):
    suma = sum(lista)
    return suma * 1.23

def vat(n):
    return n * 1.23

def vat_paragon(lista):
    return sum(map(vat, lista))

lis = (1.1, 2.0, 3.0)

print(vat_faktura(lis) == vat_paragon(lis))
print(vat_paragon(lis))
print(vat_faktura(lis))
