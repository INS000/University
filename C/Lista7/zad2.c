#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>


typedef struct{
    short day;
    short month;
    short year;
}kal;

bool mniejsze(kal *a, kal *b){
    if(a->year < b->year)
        return 0;
    if(a->year > b->year)
        return 1;
    if(a->month < b->month)
        return 0;
    if(a->month > b->month)
        return 1;
    if(a->day < b->day)
        return 0;
    if(a->day > b->day)
        return 1;
    return 0;
}

void swapcal(kal** a, kal** b){
    kal* tmp = *a;
    *a = *b;
    *b = tmp;
}


void bubleSort(kal* tab[], int n){
    for(int i = 0; i < n - 1; i++){
        // bool change = 0;
        for(int j = 1; j < n - 1; j++){
            if(mniejsze(tab[i], tab[j]) == 1){
                swapcal(&tab[j], &tab[i]);
                // change = 1;
            }
        }
        // if(change == 0)
        //     return;
    }
}




void wypiszos(kal* a){
    printf("%d.%d.%d\n", a->day, a->month, a->year);
}


int main(){
    int n;
    scanf("%d", &n);
    kal* list[n];
    for(int i = 0; i < n; i++){
        kal* dat = (kal*)malloc(sizeof(kal));
        scanf("%hd %hd %hd", &dat->year, &dat->month, &dat->day);
        list[i] = dat;
    }
    bubleSort(list, n);
    for(int i = 0; i < n; i++){
        wypiszos(list[i]);
   }
//    free(dat);
}
