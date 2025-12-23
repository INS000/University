#include <cstdio>
#include <cmath>
using namespace std;

#define DA 42
#define ZW 2000007 //<-10^6, 10^6> -> 2 * 10^6 + 1 danych
#define MIL 1000000

int data[DA];
int diff[DA];
int hist[ZW];

void clear(){
    for(int i = 0; i < ZW; i++){
        hist[i] = 0;
    }
}



bool is_done(int n){
    for(int i = 0; i < n; i++){
        hist[data[i] + MIL]++;
    }

    for(int i = 0; i < ZW; i++){
        if(hist[i] >= n / 2){
            return true;
        }
    }
    return false;
}

int solve(int n){
    int wyn = 1, pom, licz;
    for(int i = 0; i < n; i++){
        licz = 0;
        for(int j = 0; j < n; j++){
            diff[j] = abs(data[i] - data[j]);
            if(diff[j] == 0)
                licz++;
        }

        for(int j = 0; j < n; j++){
            hist[diff[j]]++;
            if(diff[j] > wyn && hist[diff[j]] >= (n/2 - licz))
                    wyn = diff[j];
            for(int k = 2; k * k <= diff[j]; k++){
                if(diff[j] % k == 0){
                    hist[k]++;
                    pom = diff[j] / k;
                    if(pom != k)
                        hist[pom]++;
                    if(k > wyn && hist[k] >= (n/2 - licz))
                        wyn = k;
                    if(pom > wyn && hist[pom] >= (n/2 - licz))
                        wyn = pom;
                }
            }
        }
        clear();
    }
    return wyn;
}

int main() {
    int t, n, wyn;
    scanf("%d", &t);
    for(int h = 0; h < t; h++){
        scanf("%d", &n);
        for(int p = 0; p < n; p++){
            scanf("%d", &data[p]);
        }
        if(is_done(n)){
            wyn = -1;
            clear();
        } else {
            clear();
            wyn = solve(n);
        }
        printf("%d\n", wyn);
    }

}
