#include<stdio.h>

char daj(char c, char l){
    if(l == c == ' ')
        return 8;
    if(c >= 'a' && c <= 'z')
        return((c - 'a' + 3) % 26 + 'a');
    if(c == 9)
        return(' ');
    if(c >= 32 && c <=126 || c == 10)
        return c;
    return 8;
}


int main(){
    char c , l='a';
    while((c = getchar()) != EOF){
        // printf("%c", daj(c, l));
        if(daj(c, l) != 8){
            putchar(daj(c, l));         
        }   
        l = c;
    }
}