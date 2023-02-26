#include <stdio.h>
int main() {
  int n, a[31];
  scanf("%d %d %d", &a[0], &a[1], &n);
  for(int i = 2; i <= n; i++)
    a[i] = a[i - 2] - a[i - 1];
  printf("%d\n", a[n]);
}