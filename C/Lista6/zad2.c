#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>


typedef struct{
    char* imie;
    char* nazwisko;
    short wiek;
    double waga;
    double wzrost;
    double BMI;
}os;

bool mniejsze(os* a, os* b){
    if(strcmp(a->nazwisko, b->nazwisko) < 0)
        return 0;
    if(strcmp(a->nazwisko, b->nazwisko) > 0)
        return 1;
    if(strcmp(a->imie, b->imie) < 0)
        return 0;
    if(strcmp(a->imie, b->imie) > 0)
        return 1;
    if(a->wiek < b->wiek)
        return 0;
    if(a->wiek > b->wiek)
        return 1;
    if(a->BMI < b->BMI)
        return 0;
    if(a->BMI > b->BMI)
        return 0;
    return 0; 
}  


void insertSort(os tab[], int n, bool (*mniejsza)(os*, os*)){
    int j;
    for(int i = 1; i < n; i++){
        os key = tab[i];
        j = i - 1;
        while(j >= 0 && mniejsza(&tab[j], &key)){
            tab[j + 1] = tab[j];
            j--;
        }
        tab[j + 1] = key;
    }
}

void wypiszos(os a){
    printf("%-12s %-12s %-3d %-5.2lf\n", a.nazwisko, a.imie, a.wiek, a.BMI);
}


int main(){
    os list[12] = {
        {"Kazimierz", "Opal", 30, 70.53, 1.83},
        {"Zbigniew", "Kapusta", 19, 90.42, 1.78},
        {"Zbigniew", "Stoklosa", 17, 69, 1.67},
        {"Anastazja", "Borowik", 23, 51, 1.60},
        {"Geodeta", "Frankowska", 37, 63, 1.68},
        {"Henryk", "Karlowicz", 27, 72, 1.79},
        {"Patryk", "Kaktusowy", 87, 68, 1.63},
        {"Antoni", "Grudzinski", 35, 92, 1.87},
        {"Leokadia", "Stachowiak", 26, 58.3, 1.57},
        {"Franciszek", "Hubzik", 39, 72.1, 1.83},
        {"Tadeusz", "Politka", 29, 80.4, 1.76},
        {"Magda", "Ochydko", 47, 83.5, 1.80}
    };
    for(int i = 0; i < 12; i++){
        list[i].BMI = list[i].waga / list[i].wzrost / list[i].wzrost;
    }
    insertSort(list, 12, (bool (*)(os *, os *))mniejsze);
    for(int i = 0; i < 12; i++){
        wypiszos(list[i]);
    }
    

}