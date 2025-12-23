#include<bits/stdc++.h>

bool hist[1005];

int ans(){
    for(int i = 1; i < 1001; i++){
        if(!hist[i])
            return i - 1;
    }
    return -69;
}

int main(){
    int n;
    int c1[6];
    int c2[6];
    int c3[6];
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        if(i==0)
        for(int j = 0; j < 6; j++){
            scanf("%d", &c1[j]);
            hist[c1[j]] = 1;
        }
        if(i==1)
        for(int j = 0; j < 6; j++){
            scanf("%d", &c2[j]);
            hist[c2[j]] = 1;
        }
        if(i==2)
        for(int j = 0; j < 6; j++){
            scanf("%d", &c3[j]);
            hist[c3[j]] = 1;
        }
    }

    if(n >= 2)
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            hist[c1[i] * 10 + c2[j]] = 1;
            hist[c2[i] * 10 + c1[j]] = 1;
        }
    }

    if(n == 3)
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            hist[c3[i] * 10 + c1[j]] = 1;
            hist[c3[i] * 10 + c2[j]] = 1;
            hist[c1[i] * 10 + c3[j]] = 1;
            hist[c2[i] * 10 + c3[j]] = 1;
        }
    }

    if(n == 3)
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            for(int k = 0; k < 6; k++){
                hist[c3[i] * 100 + c2[j] * 10 + c1[k]] = 1;
                hist[c3[i] * 100 + c1[j] * 10 + c2[k]] = 1;
                hist[c2[i] * 100 + c1[j] * 10 + c3[k]] = 1;
                hist[c2[i] * 100 + c3[j] * 10 + c1[k]] = 1;
                hist[c1[i] * 100 + c2[j] * 10 + c3[k]] = 1;
                hist[c1[i] * 100 + c3[j] * 10 + c2[k]] = 1;
            }
        }
    }

    std::cout << ans();
}
