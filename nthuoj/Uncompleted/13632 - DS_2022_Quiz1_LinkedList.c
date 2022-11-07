//huh
#include <stdio.h>
int main(){
  int n, m, cur = 0, a[1000000];
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", &a[i]);
  while(1){
    scanf("%d", &m);
    if(m == -1) break;
    cur = cur + m;
    while(a[cur] == 0) cur++;
    cur %= n;
    a[cur] = 0;
    printf("[%d]", cur);
  }
  for(int i = 0; i < n; i++)
    if(a[i] != 0) printf("%d ", a[i]);
}