#include<stdio.h>
#include<stdbool.h>

void swap(int *a, int *b){
    int tmp = *b;
    *b = *a;
    *a = tmp;
}

void selSort(int tab[], int n){
    int min;
    for(int i = 0; i < n - 1; i++){
        min = i;
        for(int j = i + 1; j < n; j++){
            if(tab[i] < tab[min])
                min = i;
        }
        if(min != i){
            swap(&tab[min], &tab[i]);
        }
    }
}

void bubSort(int tab[], int n){
    bool zmiana;
    for(int i = 0; i < n - 1; i++){
        zmiana = 0;
        for(int j = 0; j < n - i - 1; j++){
            if(tab[j] > tab[j + 1]){
                swap(&tab[j], &tab[j + 1]);
                zmiana = 1;
            }
        }
        if(zmiana == 0)
            return;
    }
}

int main(){
    int n;
    scanf("%d", &n);
    bool sito[n + 1];
    sito[0] = 0;
    sito[1] = 0;
    for(int i = 2; i <= n; i++){
        sito[i] = 1;
    }
    for(int i = 2; i <= n; i++){
        if(sito[i]){
            for(int j = i + i; j <= n; j += i){
                sito[j] = 0;
            }
        }
    }
    printf("%d %d", sito[13], sito[20]);
}