def sudan(n, x, y):
    if n == 0:
        return x + y
    elif y == 0:
        return x
    else:
        return sudan(n - 1, sudan(n, x, y - 1), sudan(n, x, y - 1) + y)

memo = {}

def sudan_memo(n, x, y):
    if (n, x, y) in memo:
        return memo[(n, x, y)]

    if n == 0:
        res = x + y
    elif y == 0:
        res = x
    else:
        pom = sudan_memo(n, x, y - 1)
        res = sudan_memo(n - 1, pom, pom + y)

    memo[(n, x, y)] = res
    return res


# print(sudan(2, 26, 1)) # 13 sek


print(sudan_memo(2, 500, 1)) #instant
