#include <stdio.h>
int main() {
  int n, m, a[25][25];
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      scanf("%d", &a[i][j]);
  for(int i = 0; i < n - m + 1; i++)
    for(int j = 0; j < n - m + 1; j++){
      int x = 0;
      for(int k = 0; k < m; k++)
        for(int l = 0; l < m; l++)
          if(a[i + k][j + l] > x) x = a[i + k][j + l];
      printf(j<n-m?"%5d":"%5d\n", x);
    }
}