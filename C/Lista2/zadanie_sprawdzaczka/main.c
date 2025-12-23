#include<stdio.h>
#include<stdlib.h>
typedef long long ll;
int tab[105][105];
ll wyn;

void gen(int w, int h){
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++) {
            char c;
            if (scanf(" %c", &c) != 1)
                continue;
            if (c >= '1' && c <= '9') {
                tab[x][y] = c - '0';
            }
    }
}

void wyp(int w, int h){
    for (int y = 0; y < h; y++){
        for (int x = 0; x < w; x++)
            printf("%d ", tab[x][y]);
        printf("\n");
    }

}

int praw(int w, int h){
    int swyn = 0;
    for(int y = 0; y < h; y++){
        int cien = 0;
        for(int x = w - 1; x >= 0; x--){
            if(cien == 0){
                if(tab[x][y] == 9){
                    swyn++;
                    cien = tab[x][y] + 1;
                }
                else if(tab[x][y] > 0){
                    tab[x][y]++;
                    cien = tab[x][y];
                }
            }
            else if(tab[x][y] >= cien)
                cien = tab[x][y] + 1;
            if(cien > 0)
                cien--;
        }
    }
    wyn += swyn;
    return swyn;
}

int dol(int w, int h){
    int swyn = 0;
    for(int x = 0; x < w; x++){
        int cien = 0;
        for(int y = h - 1; y >= 0; y--){
            if(cien == 0){
                if(tab[x][y] == 9){
                    swyn++;
                    cien = tab[x][y] + 1;
                }
                else if(tab[x][y] > 0){
                    tab[x][y]++;
                    cien = tab[x][y];
                }
            }
            else if(tab[x][y] >= cien)
                cien = tab[x][y] + 1;
            if(cien > 0)
                cien--;
        }
    }
    wyn += swyn;
    return swyn;
}

int lew(int w, int h){
    int swyn = 0;
    for(int y = 0; y < h; y++){
        int cien = 0;
        for(int x = 0; x < w; x++){
            if(cien == 0){
                if(tab[x][y] == 9){
                    swyn++;
                    cien = tab[x][y] + 1;
                }
                else if(tab[x][y] > 0){
                    tab[x][y]++;
                    cien = tab[x][y];
                }
            }
            else if(tab[x][y] >= cien)
                cien = tab[x][y] + 1;
            if(cien > 0)
                cien--;
        }
    }
    wyn += swyn;
    return swyn;
}



int main(){
    int w, h;
    ll d;
    scanf("%d %d %lld", &w, &h, &d);
    gen(w, h);

    if(d<20){
        for(int i = 0; i < d; i++){
            praw(w, h);
            dol(w, h);
            lew(w, h);
        }
    }
    else{
        int a, b, c;
        for(int i = 0; i < 19; i++){
            praw(w, h);
            dol(w, h);
            lew(w, h);
        }
        a = praw(w, h);
        b = dol(w, h);
        c = lew(w, h);
        wyn += (a + b + c) * (d - 20);
    }
    printf("%lld", wyn);

}
