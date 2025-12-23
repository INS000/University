def mandaty(lista, miejsca):
    pom2 = sum(lista) / 20
    for a in range(len(lista)):
        if lista[a] < pom2:
            lista[a] = 0
    wyn = [0] * len(lista)
    lista2 = [[i, i] for i in lista]
    while miejsca > 0:
        pom = lista2.index(max(lista2))
        wyn[pom] += 1
        lista2[pom][0] = lista2[pom][1] / (wyn[pom] + 1)
        miejsca -= 1
    return wyn

a = [720, 300, 480]
print(mandaty(a,8))
