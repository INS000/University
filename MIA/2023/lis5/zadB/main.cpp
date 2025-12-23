#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


ll tab2[100007];
ll costs[100007];

ll cost(ll k, ll n){

    for(ll i = 0; i < n; i++){
        tab2[i] = costs[i] + k * (i + 1);
    }

    sort(tab2, tab2 + n);

    ll p = 0;
    for(ll i = 0; i < k; i++){
        p += tab2[i];
    }
    return p;
}

void binsearch(ll n, ll S){
    ll l = 1, p = n, sr, k, a = 0, c = 0;
	while(l <= p){
		sr = (l + p) / 2;
        k = cost(sr, n);

		if(k <= S){
            a = sr;
            c = k;
            l = sr + 1;
        }
        else
            p = sr - 1;
    }
    cout << a << " " << c;
}

int main(){
    ll n, S;
    cin >> n >> S;
    for(ll i = 0; i < n; i++){
        cin >> costs[i];
    }
    binsearch(n, S);
}
