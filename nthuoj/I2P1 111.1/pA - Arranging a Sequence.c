#include <stdio.h>
int main(){
  int n, m;
  scanf("%d %d", &n, &m);

  int a[n+1];

  for(int i = 1; i <= n; i++){
    a[i] = i;
  }

  int remove[m];

  for(int i = 0; i < m; i++){
    scanf("%d", &remove[i]);
    a[remove[i]] = 0;
  }

  for(int i = m-1; i >= 0; i--){
    printf("%d\n", remove[i]);
  }

  for(int i = 1; i <= n; i++){
    if(a[i]) printf("%d\n", a[i]);
  }
}