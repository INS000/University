#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

bool vis[100005];
vector<long long> neigh[100005];

double horse(long long v){
    vis[v] = 1;
    double res = 0.0;
    if(neigh[v].size() == 1)
        return 0.0;
    for(int i = 0; i < neigh[v].size(); i++){
        if(!vis[neigh[v][i]]){
            res += horse(neigh[v][i]);
        }

    }
    res /= ((double)neigh[v].size());
    res += 1.0;
    return res;
}

int main(){
    int n, a, b;
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        cin >> a >> b;
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }

    cout << setprecision(12);
    cout << horse(1);
}
