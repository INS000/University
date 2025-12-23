#include <bits/stdc++.h>
using namespace std;

double zad7(double x){
    return 4046.0 * 1.0 / (sqrt(pow(x, 14) + 1.0) + 1.0);
}

double zad8(double x){
    return 14.0 * pow(sin(17.0 * x), 2) / (pow(x, 2) * (1 + cos(17 * x)));
}

double zad9(int k){
    if(k == 1) return 2;
    return pow(2, k - 1) * sqrt(2 * (1 - sqrt(1 - pow(zad9(k - 1) / pow(2, k - 1), 2))));
}

double zad9v2(int k){
    if(k == 1) return 2;
    double tmp = zad9v2(k - 1);
    return sqrt(2.0 * pow(tmp, 2) / (1 + sqrt(1 - (pow(tmp, 2) / pow(2, 2 * k - 1)))));
}


int main(){
    // cout << zad7(0.001) << '\n';

    // for(int i = -11; i >= -20; i--){
    //     cout << zad8(pow(10.0, i)) << '\n';
    // }

    for(int i = 1; i < 50; i++){
        cout << zad9(i) << ' ' << zad9v2(i) << '\n';
    }
}
