import math
import timeit


def pierwsze_imperatywna(n):
    prime = []
    for i in range(2, n + 1):
        add = True
        for j in range(2, int(math.sqrt(i)) + 1):
            if not i % j:
                add = False
                break
        if add:
            prime.append(i)
    return prime

def pierwsze_skladana(n):
    return [i for i in range(2, n + 1) if all(i % j for j in range(2, int(math.sqrt(i)) + 1))]

def pierwsze_funkcyjna(n):
    return list(filter(lambda i: all(i % j for j in range(2, int(math.sqrt(i)) + 1)), [i for i in range(2, n + 1)]))

print(f"{"n":>3}: {"czas_imp":>10}, {"czas_sklad":>10}, {"czas_funk":>10}")
for i in range(10, 101, 10):
    czas_imp = timeit.timeit("pierwsze_imperatywna(i)", number=100, globals=globals())
    czas_sklad = timeit.timeit("pierwsze_skladana(i)", number=100, globals=globals())
    czas_funk = timeit.timeit("pierwsze_funkcyjna(i)", number=100, globals=globals())
    print(f"{i:>3}: {czas_imp:.8f}, {czas_sklad:.8f}, {czas_funk:.8f}")


print(pierwsze_imperatywna(19))
print(pierwsze_skladana(20))
print(pierwsze_funkcyjna(20))
