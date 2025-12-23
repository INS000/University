#include<stdio.h>


int is_free(int x, int y, int a[]){
    for(int i = 0; i < x; i++){
        if(a[i] == y)
            return 0;
    }
    return 1;
}

int zet(int n){
    int poz[n];
    for(int i = 0; i < n; i++)
        poz[i] = -1;
    int k = 0;
    while(k < n && k >= 0){
        
    }
}