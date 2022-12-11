#include <stdio.h>
#include <stdlib.h>
int cmpfunc (int *a, int *b){return *a - *b;}
int main(){
  int n, k, c[100], ans = 0;
  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; i++) c[i] = i;
  while(k--){
    int a, b;
    scanf("%d %d", &a, &b);
    int t = c[a];
    for(int i = 0; i < n; i++)
      if(c[i] == t) c[i] = c[b];
  }
  
  qsort(c, n, sizeof(int), cmpfunc);
  for(int i = 0; i < n;){
    int cur = c[i];
    while(c[i] == cur){
      i++;
      if(c[i] != cur){
        ans++;
        break;
      }
    }
  }

  printf("%d\n", ans-1);
}