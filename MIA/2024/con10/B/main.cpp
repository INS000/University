#include<cstdio>
#include<algorithm>
using namespace std;

long long dp[510];

void zero(){
    for(int i = 0; i < 510; i++)
        dp[i] = 0;
}

long long binomialCoeff(int n, int k){
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = min(i, k); j > 0; j--){
            dp[j] = dp[j] + dp[j - 1];
        }
    }
    return dp[k];
}

int main(){
    long long n, tmp;
    scanf("%d", &n);
    tmp = binomialCoeff(n + 4, n - 1);
    zero();
    printf("%lld\n", tmp * binomialCoeff(n + 2, n - 1));
}
