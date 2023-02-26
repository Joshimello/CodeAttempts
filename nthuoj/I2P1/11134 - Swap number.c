#include <stdio.h>
int main() {
  int a[5], k;
  for (int i = 0; i < 5; i++)
    a[i] = i;
  scanf("%d", &k);
  for (int i = 0; i < k; i++){
    int x, y, t;
    scanf("%d %d", &x, &y);
    t = a[x]; a[x] = a[y]; a[y] = t;
  }
  for (int i = 0; i < 5; i++)
    printf(i < 4 ? "%d ":"%d", a[i]);
}