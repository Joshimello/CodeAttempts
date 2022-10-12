#include <stdio.h>
int main(){
  int m, n, x, a = 0;
  scanf("%d %d", &m, &n);
  for(int i = 0; i < m + n; i++){
    scanf("%d", &x);
    if(x > a) a = x;
  }
  printf("%d", a);
}