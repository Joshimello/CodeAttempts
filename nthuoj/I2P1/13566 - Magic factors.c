#include <stdio.h>
int main() {
  int n;
  scanf("%d", &n);
  printf("%d ", (n / 1000) * (n % 1000));
  printf("%d ", (n / 100) * (n % 100));
  printf("%d\n", (n / 10) * (n % 10));
}