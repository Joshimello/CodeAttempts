#include <stdio.h>
int g[20], k, s = 0;
int find(int n, int max){
  if(n == 0) s++;
  for(int i = k-1; i >= 0; i--)
    if(n-g[i] >= 0 && max >= g[i])
      find(n-g[i], g[i]);
}
int main(){
  int n;
  scanf("%d %d", &n, &k);
  for(int i = 0; i < k; i++)
    scanf("%d", &g[i]);
  find(n, g[k-1]);
  printf("%d", s);
}

/* list all possible
#include <stdio.h>
int a[999], g[20], k;
int list(int s){
  for(int i = 0; i < s; i++)
    printf(i<s-1?"%d ":"%d\n", a[i]);
}
int find(int n, int s, int max){
  if(n == 0) list(s);
  for(int i = k-1; i >= 0; i--)
    if(n-g[i] >= 0 && max >= g[i]){
      a[s] = g[i];
      find(n-g[i], s+1, g[i]);
    }
}
int main(){
  int n;
  scanf("%d %d", &n, &k);
  for(int i = 0; i < k; i++)
    scanf("%d", &g[i]);
  find(n, 0, 4);
}
*/