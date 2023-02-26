#include <stdio.h>
int main(){
  int n, m, t, a[30000] = {}, target = 0, ans = 0;
  scanf("%d %d", &n, &m);
  
  for(int i = 0; i < m; i++)
    target = (target << 1) | 1;
  
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++){
      scanf("%d", &t);
      a[i] = (a[i] << 1) | t;
    }

  for(int i = 0; i < n; i++)
    for(int j = i; j < n; j++)
      if((a[i] | a[j]) == target && i != j) ans++;
        
  printf("%d\n", ans);
}