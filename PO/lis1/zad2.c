/*
* Maksymilian Kochan
* lista 1: zad 2
* gcc zad2.c
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct Ulamek{
    int licz, mian;
}Ulamek;

int nwd(int a, int b)
{
    if (a == 0)
        return b;
    return nwd(b % a, a);
}

int nww(int a, int b){
    return a * b / nwd(a, b);
}

Ulamek *nowy_ulamek(int num, int denom){
    int pom = nwd(num, denom);
    num /= pom;
    denom /= pom;
    Ulamek *new = (Ulamek *)malloc(sizeof(Ulamek));
    new->licz = num;
    new->mian = denom;
    return new;
}

void show(Ulamek *u){
    printf("%d/%d\n", u->licz, u->mian);
}

void optimize(Ulamek *a){
    int pom = nwd(a->licz, a->mian);
    a->licz /= pom;
    a->mian /= pom;
}

//obie funkcje robia wszystkie podstawowe operacje artmetyczne 
// (jako 3 argument przyjmuja znak operacji ktora chcemy zrobic)
Ulamek *oper_art1(Ulamek *a, Ulamek *b, char op){
    if(op == '+'){
        int pom = nww(a->mian, b->mian);
        int al = a->licz * pom / a->mian;
        int bl = b->licz * pom / b->mian;
        Ulamek *c = nowy_ulamek(al + bl, pom);
        optimize(c);
        return c;
    }
    else if(op == '-'){
        int pom = nww(a->mian, b->mian);
        int al = a->licz * pom / a->mian;
        int bl = b->licz * pom / b->mian;
        Ulamek *c = nowy_ulamek(al - bl, pom);
        optimize(c);
        return c;
    }
    else if(op == '*'){
        int pom1 = nwd(a->mian, b->licz), pom2 = nwd(a->licz, b->mian);
        int al = a->licz / pom2;
        int am = a->mian / pom1;
        int bl = b->licz / pom1;
        int bm = b->mian / pom2;
        Ulamek *c = nowy_ulamek(al * bl, am * bm);
        return c;
    }
    else if(op == '/'){
        int pom1 = nwd(a->licz, b->licz), pom2 = nwd(a->mian, b->mian);
        int al = a->licz / pom1;
        int am = a->mian / pom2;
        int bl = b->mian / pom2;
        int bm = b->licz / pom1;
        Ulamek *c = nowy_ulamek(al * bl, am * bm);
        return c;
    }
}

void oper_art2(Ulamek *a, Ulamek *b, char op){
    if(op == '+'){
        int pom = nww(a->mian, b->mian);
        int al = a->licz * pom / a->mian;
        int bl = b->licz * pom / b->mian;
        b->licz = al + bl;
        b->mian = pom;      
        optimize(b);
    }
    else if(op == '-'){
        int pom = nww(a->mian, b->mian);
        int al = a->licz * pom / a->mian;
        int bl = b->licz * pom / b->mian;
        b->licz = al - bl;
        b->mian = pom;
        optimize(b);
    }
    else if(op == '*'){
        int pom1 = nwd(a->mian, b->licz), pom2 = nwd(a->licz, b->mian);
        int al = a->licz / pom2;
        int am = a->mian / pom1;
        int bl = b->licz / pom1;
        int bm = b->mian / pom2;
        b->licz = al * bl;
        b->mian = am * bm;
    }
    else if(op == '/'){
        int pom1 = nwd(a->licz, b->licz), pom2 = nwd(a->mian, b->mian);
        int al = a->licz / pom1;
        int am = a->mian / pom2;
        int bl = b->mian / pom2;
        int bm = b->licz / pom1;
        b->licz = al * bl;
        b->mian = am * bm;
    }
}

int main(){
    Ulamek *a = nowy_ulamek(18, 5);
    Ulamek *b = nowy_ulamek(15, 6);
    show(oper_art1(a, b, '*'));
    printf("\n");
    oper_art2(a, b, '*');
    show(b);
    free(a);
    free(b);
}