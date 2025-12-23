#include<stdio.h>

int hist[26][1001];
int min[1001];

int main(){
    int n = 5, k = 5;
    int tmp = scanf("%d %d", &n ,&k);
    if(tmp)
        tmp = 1;
    char tab[n][k], c;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < k; j++){
            c = getchar();
            while (c < 'a' || c > 'z')
            {
                c = getchar();
            }
            tab[i][j] = c;
        }
    }

    for(int i = 0; i < k; i++){
        for(int j = 0; j < n; j++){
            hist[tab[j][i] - 'a'][i]++;
        }
    }
    int max = 0, maxi = 0;
    for(int i = 0; i < n; i++){
        int maxloc = 0;
        for(int j = 0; j < k; j++)
            if(hist[tab[i][j]-'a'][j] == 1)
                maxloc++;
        if(maxloc > max){
            maxi = i;
            max = maxloc;
        }
    }
    for(int i = 0; i < k; i++)
        printf("%c", tab[maxi][i]);
    printf("\n%d", max);

}
