#include <stdio.h>
// #include "napisy.h"

int dl(char t[]){
    int licz = 0;
    while(t[licz])
        licz++;
    return licz;
}

void swap(char *a, char *b){
    char c = *a;
    *a = *b;
    *b = c;
}

void kop(char skad[], char dokad[]){
    int n = dl(skad);
    for(int i = 0; i <= n; i++){
        dokad[i] = skad[i];
    }
}

void odwr(char t[]){
    char c;
    int n = dl(t);
    for(int i = 0; i < n / 2; i++){
        swap(&t[n - i - 1], &t[i]);
    }
}

void wypisz(char t[], int n){
    for(int i = 0; i < n; i++)
        printf("%c", t[i]);
    printf("\n");
}

int main(int argc, char *argv[]){
    for(int i = 1; i < argc; i++){
        int d = dl(argv[i]);
        char wyn[d + 1];
        kop(argv[i], wyn);
        odwr(wyn);
        wypisz(wyn, d);
    }
}

