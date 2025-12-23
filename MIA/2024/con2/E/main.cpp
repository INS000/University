#include<cstdio>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

int c[100003], w[100003], coins[100003], notes[100003];


int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++){
        scanf("%d", &c[i]);
    }

    for(int i = 0; i < n; i++){
        scanf("%d", &w[i]);
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> dissat;
    pair<int, int> temp;
    long long penalty = 0;

    for(int i = 0; i < n; i++){
        notes[i] = c[i] / 100;

        if(c[i] % 100 != 0)
            dissat.push(make_pair((100 - (c[i] % 100)) * w[i], i));
        else
            continue;

        coins[i] = c[i] % 100;

        if (m >= c[i] % 100){
            m -= (c[i] % 100);
        } else {
            temp = dissat.top();
            dissat.pop();
            penalty += temp.first;
            m += 100 - (c[i] % 100);
            coins[temp.second] = 0;
            notes[temp.second]++;
        }
    }

    printf("%lld\n", penalty);
    for(int i = 0; i < n; i++){
        printf("%d %d\n", notes[i], coins[i]);
    }
}
