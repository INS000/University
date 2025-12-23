#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define n 6 //rozmiar szachownicy
int b[n];
void init(){
    int i;
    for(i=0; i<n; i++) 
        b[i]=-1;
}

int isfree(int x, int y){
    int i;
    for(i = 0; i < x; i++)
        if(b[i] - i == y - x || b[i] + i == y + x || b[i] == y) 
            return 0;
    return 1;
}

int queens(){
    int k = 1;
    b[0] = 0;
    int wyn = 0;
    while(k < n && k >= 0){
        do{
            b[k]++;
        }while(b[k] < n && !isfree(k, b[k]));
        if (b[k] < n)
            k++; 
        else{
            b[k] = -1;
            k--;
        }
    }
    wyn++;
    // return k;
}

void drawresult(){
    int i, j;
    printf("\n");
    for(i=0; i<n; i++) 
        printf("%d ", b[i]);
    printf("\n\n");
    for(i=0; i<n; i++){
        for(j=0; j<n; j++)
            if(b[j]==i) 
                printf("x ");
            else 
                printf("o ");
        printf("\n");
    }
}

bool poprawne(int t[], int np){
    for(int i = 0; i < np - 1; i++){
        for(int j = i + 1; j < np; j++){
            if(t[i] == t[j] || t[i] + i == t[j] + j || t[i] - i == t[j] - j)
                return 0;
        }
    }
    return 1;
}

int tab[105][105];

void wpisz(int ni, int m){
    for(int i=0; i<ni; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &tab[i][j]);
        }
    }
}

int min(int a, int b){
    if(a < b)
        return a;
    return b;
} 

int straw(int ni, int m){
    for(int i=1; i<=ni; i++){
        for(int j=1; j<=m; j++){
            tab[i][j] += min(tab[i-1][j], tab[i][j-1]);
        }
    }
    return tab[ni][m] + tab[0][0];
}


int main(){
    wpisz(3, 3);
    printf("%d", straw(2, 2));
    // init();
    // if(queens() == n) 
    //     drawresult();
    // else 
    //     printf("brak rozwiazania");
    // system("pause");
}

