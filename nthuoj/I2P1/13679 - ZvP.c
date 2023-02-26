#include <stdio.h>
int n, sol = 0, a[10][10], v[10][10];
long m = -1e10;
int can(int x, int y){
  for(int i = 0; x-i >= 0; i++)
    if(a[x-i][y]) return 0;
  for(int i = 0; x-i >= 0 && y-i >= 0; i++)
    if(a[x-i][y-i]) return 0;
  for(int i = 0; x-i >= 0 && y+i < n; i++)
    if(a[x-i][y+i]) return 0;
  return 1;
}
void find(int x, long s){
  if(x == n){
    if(s > m){
      m = s;
      sol = 1;
    }
    return;
  }
  for(int i = 0; i < n; i++)
    if(can(x, i)){
      a[x][i] = 1;
      // debug uwu
      // for(int k = 0; k < n; k++)
      //   for(int j = 0; j < n; j++)
      //     printf(j<n-1?"%d ":"%d\n", a[k][j]);
      // printf("\n");
      find(x+1, s+v[x][i]);
      a[x][i] = 0;
    }
}
int main(){
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      scanf("%d", &v[i][j]);
  find(0, 0);
  printf(sol?"%ld\n":"no solution\n", m);
}
