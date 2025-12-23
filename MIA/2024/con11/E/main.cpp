#include<cstdio>
#include<vector>
using namespace std;

vector<int> neigh[1000002];
bool visited[1000002];
bool visited2[1000002];

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> leaders, ans;
    for(int i = 0; i < m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
    }

    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            visited[i] = true;
            for(int j = 0; j < neigh[i].size(); j++){
                visited[neigh[i][j]] = true;
            }
            leaders.push_back(i);
        }
    }

    for(int i = leaders.size() - 1; i >= 0; i--){
        if(!visited2[leaders[i]]){
            visited2[leaders[i]] = true;
            ans.push_back(leaders[i]);
            for(int j = 0; j < neigh[leaders[i]].size(); j++){
                visited2[neigh[leaders[i]][j]] = true;
            }
        }
    }

    printf("%d\n", ans.size());
    for(auto i : ans){
        printf("%d ", i);
    }






    return 0;
}
