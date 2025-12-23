#include <stdio.h>
unsigned fib[50];

unsigned gen(unsigned n){
    unsigned i = 2;
    fib[0] = 0;
    fib[1] = 1;
    while(fib[i-1] < n){
        fib[i] = fib[i-1] + fib[i-2];
        i++;
    }
    // printf("%u %d\n", fib[i-1], i - 1);
    if(n == fib[i-1])
        return i - 1;
    return i - 2;
}

void solve(unsigned n){
    unsigned i = gen(n), j = i - 1;
    // printf("%d\n", i);
    if(n == 0){
        printf("%c", '0');
        return;
    }
    if(n == 1){
        printf("%c", '1');
        return;
    }
    while(j > 0){
        if(fib[i] <= n){
            // printf("%d %d", fib[i], fib[i-2]);
            printf("%c", '1');
            n -= fib[i];
            i--;
            j--;
        }
        else{
            i--;
            j--;
            printf("%c", '0');
        }

    }
    // return wyn;
}


int main(){
    unsigned n;
    scanf("%u", &n);
    gen(n);
    solve(n);
    /*printf("%d\n", gen(n));
    for(int i = 0; i < 10; i++){
        printf("%u ", fib[i]);
    }*/
}
