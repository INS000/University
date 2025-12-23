#include<stdio.h>
#include<stdlib.h>

int min;

int minm(int a[], int l, int p){ 
    int mi1, mi2;
    if (l==p) 
        min =  a[l];
    else
    if (p-l==1)
        if (a[l]<a[p]) 
            min = a[l];
        else
            min = a[p];
        else{ 
            minm(a,l,(l+p)/2);
            mi1 = min;
            minm(a,(l+p)/2+1,p);
            mi2 = min;
            min = mi1<mi2 ? mi1 : mi2;
        }
    return min;
}

void hanoi(int n, int z, int s, int d){
    if(n == 1){
        printf("\nPrzenies gorny dysk z patyka %d  na patyk %d", z, d);
        return;
    }
    hanoi(n-1, z, d, s);
    printf("\nPrzenies gorny dysk z patyka %d  na patyk %d", z, d);
    hanoi(n-1, s, z, d);
}


int main(){
    int tab[7] = {7, 4, 2, 6, 9, 6, 8};
    hanoi(4, 1, 2, 3);
}