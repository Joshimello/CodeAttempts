#include <stdio.h>
int main(){
  long f[50], g[50], n;
  scanf("%d %d %d %d %d", &f[0], &f[1], &g[0], &g[1], &n);
  for(int i = 2; i <= n; i++){
    f[i] = f[i-1] + (i%2?g[i-2]:g[i/2]);
    g[i] = g[i-1] + (i%3?f[i-2]:f[i/3]);
  }
  printf("%ld %ld\n", f[n], g[n]);
}