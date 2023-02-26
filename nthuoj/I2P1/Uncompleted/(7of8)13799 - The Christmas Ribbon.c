#include <stdio.h>
int main(){
  int n, k, a[1000000], ans = 0;
  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; i++)
    scanf("%d", &a[i]);
  
  int t[1000000] = {0};
  for(int j = 0; j < k; j++)
    t[a[j]]++;

  for(int j = 1; j <= k; j++){
    // printf("%d ", t[j]);
    if(!t[j]) goto con; 
  }
  ans++;

  con:;
  for(int i = k; i < n; i++){
    
    t[a[i]]++;
    t[a[i-k]]--;
    
    for(int j = 1; j <= k; j++){
      // printf("%d ", t[j]);
      if(!t[j]) goto cont; 
    }
    ans++;

    cont:;
  }
  printf("%d\n", ans);
}