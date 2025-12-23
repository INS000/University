#include <bits/stdc++.h>
using namespace std;

double zad2(double x){
    return 4046 * (sqrt(pow(x, 14) + 1) - 1) / pow(x, 14);
}

double zad3a(double x){
    return 14 * (1 - cos(17 * x)) / pow(x, 2);
}

float zad3b(float x){
    return 14 * (1 - cos(17 * x)) / pow(x, 2);
}

double zad4(int x){
    if(x == 0)   return 1;
    if(x == 1)   return -1.0/9;
    return 80.0 / 9.0 * zad4(x - 1) + zad4(x - 2);
}

double zad5(int x){
    if(x == 0)  return log(2024.0 / 2023);
    return 1.0 / x - 2023.0 * zad5(x - 1);
}

double zad6(int a){
    double sum = 0.0;
    int tmp = 1;
    for(int i = 0; i < a; i++){
        sum += 4.0 * tmp / (2.0 * i + 1.0);
        tmp *= -1;
    }
    return sum;
}

int main(){
    // for(int i = -1; i >= -20; i--){
    //     cout << i << '\n' << zad3a(pow(10, i)) << '\n' << zad3b(pow(10, i)) << "\n\n";
    // }

    // for(int i = 0; i <= 50; i++){
    //     cout << i <<": " << zad4(i) <<'\n';
    // }

    // cout << setprecision(9) << zad6(2000000);

    for(int i = 1; i <= 19; i += 2){
        cout << i << ":  " << zad5(i) << "    " << zad5(i + 1) << '\n';
    }
}
