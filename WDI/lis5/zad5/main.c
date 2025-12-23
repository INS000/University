#include<stdio.h>


int find(int n, int *k){
    int wyn = 1;
    for(int i = 2; wyn < n; i++){
        wyn *= i;
        *k = i;
    }
    wyn /= *k;
    *k = *k - 1;
    return wyn;
}

int zad2(int n){
    int k, wyn = 0;
    int sil = find(n, &k);
    while(n > 0){
        if(n > sil){
            wyn += (n / sil);
            n -= ((wyn % 10) * sil);
        }
        wyn *= 10;
        sil /= k;
        k--;
    }
    return wyn;
}

int zad4(int n){
    int a = 1, b = 1, c = 1, d = 1;
    for(int i = 3; i <= n; i++){
        d = a + b + c;
        a = b;
        b = c;
        c = d;
    }
    return d;
}

int zad5r(int n, int m){
    if(n == 0)
        return m;
    if(m == 0)
        return n;
    return zad5r(n-1, m) + 2 * zad5r(n, m-1);
}

int zad5i(int n, int m){
    int curr[n + 1], prev[n + 1];
    if(m == 0)
        return n;
    if(n == 0)
        return m;
    for(int i = 0; i <= n; i++){
            prev[i] = i;
    }
    for(int i = 1; i <= m; i++){
        curr[0] = i;
        for(int j = 1; j <= n; j++){
            curr[j] = prev[j] * 2 + curr[j - 1];
        }
        for(int j = 0; j <= n; j++){
            prev[j] = curr[j];
        }
    }

    return curr[n];
}

int zad6(int k, int r){
    int a = 0, b = 1 % r, c = 0;
    for(int i = 2; i <= k; i++){
        c += a;
        c += b;
        c %= r;
        a = b;
        b = c;
        c = 0;
    }
    return b;
}



int main(){
    printf("%d", zad6(18, 15));

    
}
