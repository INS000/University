/*
* Maksymilian Kochan
* lista 1: zad4
* gcc zad4.c
*/

#include<stdio.h>

//ze wzgledu na alokacje miejsca na stringa maksymalne y2 i x2 to 100

void tabliczka(float x1, float x2, float y1, float y2, float skok){
    printf("         ");
    for(float i = y1; i <= y2; i+= skok){
        printf("%9.2f", i);
    }
    printf("\n");
    for(float i = x1; i <= x2; i += skok){
        printf("%8.2f:", i);
        for(float j = y1 ; j <= y2; j += skok){
            printf("%9.2f", i * j);
        }
        printf("\n");
    }
}


int main(){
    tabliczka(0, 90, 15, 80, 5);
}