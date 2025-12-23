#include <stdio.h>
#include <stdbool.h>

typedef struct{
    short h, m, s;
}zegar;

static const zegar midnight = {0, 0, 0};

bool sprawdz(zegar z){
    if(z.h < 0 || z.h  >= 24)
        return false;
    if(z.m < 0 || z.m >= 60)
        return false;
    if(z.s < 0 || z.s >= 60)
        return false;
    return true;
}

zegar normuj(zegar z){
    z.m += z.s / 60;
    z.s %= 60;
    if(z.s < 0){
        z.s += 60;
        z.m--;
    }  
    z.h += z.m / 60;
    z.m %= 60;
    if(z.m < 0){
        z.m += 60;
        z.h--;
    }  
    z.h %= 24;
    if(z.h < 0)
        z.h += 24;
    return z;
}

zegar ustaw(short h, short m, short s){
    zegar z;
    z.h = h;
    z.m = m;
    z.s = s;
    z = normuj(z);
    return z;
}

void dodajh(zegar *z, short g){
    z->h = z->h + g;
    *z = normuj(*z);
}

void dodajm(zegar *z, short m){
    z->m = z->m + m;
    *z = normuj(*z);
}

void dodajs(zegar *z, short s){
    z->s = z->s + s;
    *z = normuj(*z);
}

void drukuj(FILE *f, zegar z){
    fprintf(f, "%02d:%02d:%02d", z.h, z.m, z.s);
}

int main(){
    zegar z;
    z = ustaw(7, 70, 30);
    drukuj(stdout,  z);
    printf("\n");
    drukuj(stdout,  midnight);
    printf("\n");
    dodajh(&z, 20);
    dodajm(&z, 30);
    drukuj(stdout,  z);
    
    

}