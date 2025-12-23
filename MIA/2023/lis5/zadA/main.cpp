#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int a[n], res[m];
    pair<int, int> b[m];

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 0; i < m; i++){
        cin >> b[i].first;
        b[i].second = i;
    }

    sort(a, a+n);
    sort(b, b+m);

    int counter = 0;

    for(int i = 0; i < m; i++){
        while(b[i].first >= a[counter] && counter < n){
            counter++;
        }
        res[b[i].second] = counter;
    }

    for(int i = 0; i < m; i++){
        cout << res[i] << ' ';
    }
}
