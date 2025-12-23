#include<iostream>
using namespace std;

int a[3003];

int solve(int n, int k){
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int res = INT_MAX;


    for(int i = 1; i <= a[0]; i++){
        int min_cost = i;
        for(int j = 0; j < n; j++){
            // int p = min(k, a[j] / i);
            int p = min(k, (i ? (a[j] / i) : k));
            min_cost = max(min_cost, a[j] / p);
        }
        res = min(res, min_cost - i);
    }
    return res;
}

int main()
{
    int t, n, k;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        cin >> n >> k;
        cout << solve(n, k) << "\n";
    }
    return 0;
}
