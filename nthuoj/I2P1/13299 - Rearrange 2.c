#include <stdio.h>
int main() {
  int n, m, q;
  scanf("%d %d %d", &n, &m, &q);
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
  for(int i = 0; i < q; i++){
    int p;
    scanf("%d", &p);
    printf(i<q-1?"%d ":"%d\n", b[p]);
  }
}