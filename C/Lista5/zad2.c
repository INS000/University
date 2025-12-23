#include <stdio.h>
#include<stdbool.h>

unsigned jakiBit(unsigned liczba, unsigned nrBitu){
    unsigned l = 1 << nrBitu;
    liczba = liczba & l;
    liczba = liczba >> nrBitu;
    return liczba & 1;
}

void change(int *n, int s){
        int tmp = *n >> (s * -1);
        *n = *n << s;
        *n = *n | tmp;
}

int main(){
    int n, s;
    scanf("%d %d", &n, &s);
    change(&n, s);
    for(int i=31; i>=0; i--){
        printf("%u",jakiBit(n,i));
    }
}