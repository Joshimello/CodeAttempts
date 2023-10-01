#include <stdio.h>
int main() {
  int n, m, x, y;
  scanf("%d %d", &n, &m);
  x = (-m + 7 * n) / 2;
  y = n - x;
  printf("%d %d\n", x, y);
}