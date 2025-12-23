#include <stdio.h>
#include<stdbool.h>

unsigned jakiBit(unsigned liczba, unsigned nrBitu){
    unsigned l = 1 << nrBitu;
    liczba = liczba & l;
    liczba = liczba >> nrBitu;
    return liczba & 1;
}

void zmienBit (unsigned *liczba, unsigned nrBitu){
    unsigned l = 1 << nrBitu;
    *liczba = *liczba ^ l;
}


int main(){
    unsigned n = 0, ile = 0, bit = 1;
    scanf("%u", &n);
    zmienBit(&n, 32);
    for(int i = 1; i <= 32; i++){
        unsigned d = jakiBit(n, i);
        printf("%u", d);
        if(d == 1)
            ile++;
    }
    printf("\n");
    if(n!=0){
        while(!(jakiBit(n, bit)))
            bit++;
        for(int i = bit; i <= 32; i++){
            printf("%u", jakiBit(n, i));
        }
        printf("\n%u\n", 32 - bit);
    }else
        printf("\n0\n");
    
    

}