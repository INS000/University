#include<stdio.h>



int main(){
    int n, sp;
    int x = scanf("%d", &n);
    if(n>=1 && n<=20 && x==1){
        sp = 2*(n-1) - 1;
        for(int i = 0; i<n; i++){
            for(int j = 0; j < i; j++){
                printf(" ");
            }
            printf("*");
            for(int j = 0; j < sp; j++){
                printf(" ");
            }
            sp-=2;
            if(i<(n-1))
                printf("*");
            printf("\n");
        }
    }
    else
    {
        printf("Podałeś zły input");
    }
    
}
/*
*       * 7    2*(n-1) -1     n=5
 *     *  5
  *   *   3
   * *    1
    * 0*/