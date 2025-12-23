#include<bits/stdc++.h>
using namespace std;

const long long limit = 1000000000009;
const int limit2 = 1000007;
bool isPrime[limit2];

int main() {
    isPrime[0] = true;
    isPrime[1] = true;
    for(long long i = 2; i < limit2; i++) {
        if(isPrime[i] == false) {
            for(long long j = i * 2; j < limit2; j += i) {
                isPrime[j] = true;
            }
        }
    }
    long long n, tmp, a;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a;
        tmp = sqrt(a);
        if(!isPrime[tmp] && tmp * tmp == a) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
}
