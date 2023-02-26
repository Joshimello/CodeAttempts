#include <stdio.h>
int main(){
  int n, a, b, c;
  scanf("%d\n%d %d %d", &n, &a, &b, &c);
  int dif = b - a, mod = (c - b) - (b - a);
  for(int i = 0; i < n; i++){
    printf(i==n-1?"%d\n":"%d ", a);
    a += dif; dif += mod;
  }
}