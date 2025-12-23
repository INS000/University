#include <stdio.h>

int czybezkw(int n) {
  for (int i = 2; i * i <= n; i++)
    if (n % (i * i) == 0)
      return 0;
  return 1;
}

int solve(int n) {
  for (int i = n; i <= n + 1000; i++) {
    if (czybezkw(i))
      return i;
  }
  return -1;
}

int main(void) {
  int n;
  scanf("%d", &n);
  if (solve(n) == -1)
    printf("BRAK");
  else
    printf("%d", solve(n));
}
