#include<stdio.h>
#include<stdbool.h>
#include <math.h>
#define ll long long


int main(){
    ll d;
    int c = scanf("%lld", &d);
    if(c == 0){
        return 0;
    }
    for(ll a = d - 2; a > 0; a--){
        for(ll b = d - 1; b >= a; b--){
            ll tmp = d * d - a * a - b * b;
            ll c = sqrt(tmp);
            if (tmp > 0){
                if(c * c == tmp && c >= b){
                   printf("%lld %lld %lld", c, b, a);
                    return 0;
                }
            }
        }
    }

        printf("BRAK");

}
