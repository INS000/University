def tabliczka(x1, x2, y1, y2, d):
    x = [i * d + x1 for i in range(int((x2 - x1) // d + 1))]
    y = [i * d + y1 for i in range(int((y2 - y1) // d + 1))]
    mnoz = [a * b for a in y for b in x]
    pom = max(list(map(lambda j: len(str(j)), mnoz)))
    x.insert(0, '')
    for a in x:
        print(f'{a:>{pom + 1}}', end='')
    tmp = len(x) - 1
    for i in range(0, len(y)):
        print()
        print(f'{y[i]:>{pom + 1}}', end='')
        for j in range(0, tmp):
            print(f'{mnoz[j + i * tmp]:>{pom + 1}}', end='')


tabliczka(3.0, 5.0, 2.0, 4.0, 1.0)
