#include<iostream>
using namespace std;

int arr [1003][1003];

void gen(int x, int y, int n){
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++){
            arr[i + 4 * y][j + 4 * x] = i * 4 + j
                        + x * 16
                        + y * 16 * (n / 4);
        }
    }
}


int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n / 4; i++) {
        for(int j = 0; j < n / 4; j++){
            gen(j, i, n);
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++){
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}
