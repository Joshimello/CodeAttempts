#include <stdio.h>
int main(){
  int n, d, t;
  scanf("%d", &n);
  int a[n][n], b[n][n];
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++){
      scanf("%d", &t);
      a[i][j] = t;
    }
  scanf("%d", &d);
  for(int i = 0; i < d / 90; i++){
    for(int j = 0; j < n; j++)
      for(int k = 0; k < n; k++)
        b[j][k] = a[j][k];
    for(int j = n - 1; j >= 0; j--)
      for(int k = 0; k < n; k++)
        a[n-1-j][k] = b[k][j];
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++)
      printf(j<n-1?"%d ":"%d", a[i][j]);
    printf("\n");
  }
}