#include<stdio.h>
#include<stdbool.h>

int zad1a(int n){
    if(n % 2)
        return n * (-1);
    return n;
}

double zad1b(int n){
    double wyn = 0;
    for(int i = 1; i < n; i++){
        wyn += zad1a(i) / i;
    }
    return wyn;
}

int zad1c(int n, int x){
    int wyn = 0;
    int xp = x;
    for(int i = 1; i < n; i++){
        wyn += i * x;
        x *= xp;
    }
    return wyn;
} 


int NWD(int a, int b){
    int pom;
    while(b != 0){
        pom = b;
        b = a % b;
        a = pom;
    }
    return a;
}

int zad2a(int a, int b){
    return a * b / NWD(a, b); 
}

void zad2b(int a, int b){
    int nwd = NWD(a, b);
    a /= nwd;
    b /= nwd;
    printf("%d / %d", a, b);
}


int zad3(int n){
    int a, nwd;
    scanf("%d", &a);
    nwd = a;
    for(int i = 0; i < n-1; i++){
        scanf("%d", &a);
        nwd = NWD(a, nwd);
    }
    return nwd;
}


void zad4(int n, int k){
    int czyn[10001] = {}; //liczba <= sto milion
    int tab[k], max = 0;
    for(int i = 0; i < k; i++){
        scanf("%d", &tab[i]);
    }
    int i = 2;
    while(n > 1){
        while(n % i == 0){
            czyn[i]++;
            n /= i;
        }
        i++;
    }
    for(int i = 0; i < k; i++){
        if(czyn[tab[i]] > max)
            max = czyn[tab[i]];
    }
    printf("%d ", max);
    for(int i = 0; i < k; i++){
        if(czyn[tab[i]] == max)
            printf("%d ", tab[i]);
    }
}


int zad5(int n){
    int roz[32];
    int len = 0;
    while(n > 0){
        roz[len] = n % 2;
        n /= 2;
        len++;
    }
    for(int i = 0; i < len / 2; i++)
        if(roz[i] != roz[len - i - 1])
            return 0;
    return 1;
}


int change(int n, int k, char bit[]){
    int i = 0;
    while(n > 0){
        if(n % k < 10)
            bit[i] = n % k + '0';
        else{
            bit[i] = n % k + 'A' - 10;
        }
        n /= k;
        i++;
    }
    return i;
}

int zad6(int n, int k){
    char bit[32];
    int len = change(n, k, bit);
    for(int i = 0; i < len / 2; i++)
        if(bit[i] != bit[len - i - 1])
            return 0;
    return 1;
}


int zad7(int n){
    int hist[10] = {};
    while(n > 0){
        hist[n % 10]++;
        n /= 10;
    }
    int k = 0;
    for(int i=0; i < 10; i++){
        if(hist[i] > 0)
            k++;
    }
    return k;
}


int zad8(int n, int m){
    int hist1[10] = {};
    int hist2[10] = {};
    while(n > 0){
        hist1[n % 10]++;
        hist2[m % 10]++;
        n /= 10;
        m /= 10;
    }
    int k = 0;
    for(int i=0; i < 10; i++){
        if(hist1[i] != hist2[i])
            return 0;
    }
    return 1;
}



int main(){
    printf("%d", zad7(20));
}