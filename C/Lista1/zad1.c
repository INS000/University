#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int main(){
    srand(time(0));
    int n;
    scanf("%d", &n);
    double min = 2, max = -1, c;
    for(int i = 0; i < n; i++){
        c = rand() / (double)RAND_MAX;
        if(min > c)
            min = c;
        if(max < c)
            max = c;
    }
    printf("Najmniejsza wylosowana wartosc to: %.3lf\nNajwieksza wylosowana liczba to: %.3lf\n", min, max);
}
