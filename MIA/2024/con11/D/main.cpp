#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

#define siz 100005

vector<int> c_diff;
vector<int> d_diff;

int c[siz], d[siz];


int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &c[i]);
    }

    for(int i = 0; i < n; i++){
        scanf("%d", &d[i]);
    }

    for(int i = 0; i < n - 1; i++){
        c_diff.push_back(c[i] - c[i + 1]);
        d_diff.push_back(d[i] - d[i + 1]);
    }

    sort(c_diff.begin(), c_diff.end());
    sort(d_diff.begin(), d_diff.end());

    if(c_diff == d_diff && c[0] == d[0]){
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
