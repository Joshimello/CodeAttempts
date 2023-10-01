#include <stdio.h>
int main(){
  int n, m;
  scanf("%d %d", &n, &m);
  int a[n][m], b[m][n], c[n][n];
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      scanf("%d", &a[i][j]);
  for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++)
      scanf("%d", &b[i][j]);
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++){
      int s = 0;
      for(int k = 0; k < m; k++)
        s += a[i][k] * b[k][j];
      c[j][i] = s;
    }
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      printf(j<n-1?"%d ":"%d\n", c[i][j]);
}