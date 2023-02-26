#include <stdio.h>
int main(){
  long long int a, b, c, d, n, f[1000], g[1000];
  scanf("%d %d %d %d %d", &f[0], &f[1], &g[0], &g[1], &n);
  for(int i = 2; i <= n; i++){
    f[i] = f[i-1] + (i%3==0 ? g[f[i/3]%i] : g[i-2]);
    g[i] = g[i-1] + (i%5==0 ? f[g[i/5]%i] : f[i-2]);
  }
  printf("%lld %lld\n", f[n], g[n]);
}