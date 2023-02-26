// wrong order
#include <stdio.h>
int n, a[5];
void out(){
  printf("(");
  for(int i = 0; i < n; i++)
    printf(i<n-1?"%d,":"%d)\n", a[i]);
}
int can(int m, int i){
  for(int j = m; j >= 0; j--)
    if(a[j] == i) return 0;
  return 1;
}
void add(int m){
  if(m == n) out();
  for(int i = 1; i <= n; i++)
    if(can(m, i)){
      a[m] = i;
      add(m+1);
    } 
}
int main(){
  scanf("%d", &n);
  add(0);
}