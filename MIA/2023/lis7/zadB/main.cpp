#include<iostream>

int main(){
    long long n;
    long long pom, pom2;
    std::cin >> n;
    pom = n * (n - 1) * (n - 2) * (n - 3) * (n - 4);
    pom2 = pom / 120;
    std::cout << pom2 * pom;
}
