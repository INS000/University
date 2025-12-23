#include<stdio.h>
#include<stdlib.h>




int main(int argc, char *argv[]){
    char *T = argv[1];
    char B;
    int k = 0;
    int N;
    scanf("%d", &N);
    while(N > 0){
        k=0;
        for(int i = 0 ;;i++){
            if(T[i] == '\0'){
                // B = T[i-1];
                break;
            }
            
            k = (k * 10 + (T[i] - '0')) % N;
        }
        if(k == 0){
            printf("Tak\n");
        }
        else
        {
            printf("Nie\n");       
        }
        scanf("%d", &N);

    }
    // printf("%c\n", B);
    

}