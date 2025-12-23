#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

void zeruj(int k, int wyn[]) {
  for (int i = 0; i < k; i++)
    wyn[i] = 0;
}


void change(int n, int k, int wyn[]) {
  int sig = pow(2, k-1);
  int tmp = sig * (-1);
  int h = sig / 2;
  if (n < 0) {
    int i = 1;
    wyn[0] = 1;
    while (tmp < n) {
      if (tmp + h <= n) {
        wyn[i] = 1;
        tmp += h;
      }
      h /= 2;
      i++;
    }
  } else {
    int i = 1;
    while (n > 0) {
      if (h <= n) {
        wyn[i] = 1;
        n -= h;
      }
      i++;
      h /= 2;
    }
  }
  return;
}

int main() {
  int n, k;
  int iter;
  cin >> n >> k;
  iter = k;
  int wyn[k];
  zeruj(k, wyn);
  change(n, k, wyn);
  for (int i = 0; i < iter; i++) {
    cout << wyn[i];
  }
}