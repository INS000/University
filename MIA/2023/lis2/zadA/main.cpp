#include<bits/stdc++.h>

// int r[402];
// int l[402];

int tab[201][201];


int main(){
    int t, n, m;

    int tmp;
    std::pair<int, int> znak[4];

    for(int i = 0; i < 4; i++){
        if(i < 2)
            znak[i].first = 1;

        if(i >= 2)
            znak[i].first = -1;

        if(i % 2)
            znak[i].second = 1;

        if(!(i % 2))
            znak[i].second = -1;
    }

    scanf("%d", &t);

    for(int h = 0; h < t; h++){
        scanf("%d %d", &n, &m);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                scanf("%d", &tmp);
                tab[i][j] = tmp;
            }
        }

        int maxi = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int sum = tab[i][j];
                for(int h = 0; h < 4; h++){
                    int a = i + znak[h].first, b = j + znak[h].second;
                    while(a < n && b < m && a >= 0 && b >= 0){
                        sum += tab[a][b];
                        a += znak[h].first;
                        b += znak[h].second;
                    }
                }
                if(maxi < sum)
                    maxi = sum;
            }
        }
        printf("%d\n", maxi);
    }

    // int maxi = 0;
    // int mini = std::min(n, m);


    // for(int i = 0; i < n + m - 1; i++){
    //     if(i - 2 >= 0){
    //         tmp = r[i] + l[i - 2] - tab[(i + i - 2 - m - 1) / 2][(m - 3)]
    //         if(maxi < r[i] + l[i - 2] - )
    //             maxi =
    //     }
    // }


}
