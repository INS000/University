#include<iostream>
// #include<vector>
using namespace std;



int main()
{
    int T;
    int n, m, a;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> n >> m;
        int s = 0;
        for(int j = 0; j < n; j++)
        {
            cin >> a;
            s += a;
        }
        s*=2;
        if(n > m || n == 2){
            cout << -1 << endl;
        }
        else{
            cout << s << endl;
            for(int j = 1; j < n; j++)
            {
                cout << j << " " << j + 1 << endl;
            }
            cout << n << " " << 1 << endl;
        }
    }
}
