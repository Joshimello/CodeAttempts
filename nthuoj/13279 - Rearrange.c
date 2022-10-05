#include <stdio.h>
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int a[n + 1], b[n + 1];
  for(int i = 0; i <= n; i++)
    a[i] = i;
  for(int i = 0; i < m; i++){
    int x, y, t;
    scanf("%d %d", &x, &y);
    t = a[x]; a[x] = a[y]; a[y] = t;
  }
  for(int i = 1; i <= n; i++)
    b[a[i]] = i;
  for(int i = 1; i <= n; i++){
    printf(i<n?"%d ":"%d\n", b[i]);
  }
}