def max_sublist_sum(lista):
    maxsum = lista[0]
    maxe = lista[0]
    maxi = 0
    maxj = 0
    for i in range(len(lista)):
        maxe = max(lista[i], maxe + lista[i])
        if(maxe > maxsum):
            maxj = i
            maxsum = maxe
    suma = lista[maxj]
    maxi = maxj
    while suma != maxsum:
        maxi -= 1
        suma += lista[maxi]
    return(maxi, maxj)

a = [1, -3, 2, 1, -1]
print(max_sublist_sum(a))
