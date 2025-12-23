#include<iostream>
#include<algorithm>
using namespace std;

int black[1002], blacks[1002], white[1002], whites[1002];

int dp[1002][2];

static inline int blacks_count(int a, int b){
    return blacks[b] - blacks[a] + black[a];
}

static inline int whites_count(int a, int b){
    return whites[b] - whites[a] + white[a];
}

void load_barcode(int n, int m){
    char c;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> c;
            if(c == '#'){
                black[j]++;
            }
            else{
                white[j]++;
            }
        }
    }
}

int main(){
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    load_barcode(n, m);
    for(int i = 1; i <= m; i++){
        blacks[i] = blacks[i - 1] + black[i];
        whites[i] = whites[i - 1] + white[i];
    }

    dp[0][0] = 0;
    dp[0][1] = 0;

    int dpi, minw[2];

    for(int i = 1; i <= m; i++){
        minw[0] = 20000000;
        minw[1] = 20000000;
        for(int j = x; j <= y; j++){
            if(i >= j){
                minw[0] = min(minw[0], dp[i - j][1] + blacks_count(i - j + 1, i));         //ostatni bialy
                minw[1] = min(minw[1], dp[i - j][0] + whites_count(i - j + 1, i));         //ostatni czarny
            }

        }
        dp[i][0] = minw[0];
        dp[i][1] = minw[1];
    }

    cout << min(dp[m][0], dp[m][1]);

}
