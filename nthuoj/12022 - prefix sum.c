#include <stdio.h>
int main(){
  int n, m;
  unsigned long a[1000000];
  a[0] = 0;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++){
    int t;
    scanf("%d", &t);
    a[i] = t + a[i - 1];
  }
  scanf("%d", &m);
  for(int i = 0; i < m; i++){
    int l, r, s = 0;
    scanf("%d %d", &l, &r);
    printf("%lu\n", a[r] - a[l - 1]);
  }
}