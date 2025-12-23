#include <stdio.h>

char tab[80];
 
int change(long long d, int k){
    int i = 0;
    while(d > 0){
        if(d % k < 10)
            tab[i] = d%k + '0';
        else{
            tab[i] = d % k + 'A' - 10;
        }
        d /= k;
        i++;
    }
    return i;
}

int main(){
    long long d;
    int k, h;
    int x = scanf("%lld %d", &d, &k);
    if(k >=2 && k<=36 && x == 2){
        h = change(d, k);
        for(h; h >= 0; h--){
            printf("%c", tab[h]);
        }
        printf("\n");
    }
    else{
        printf("Zly input");
    }



}