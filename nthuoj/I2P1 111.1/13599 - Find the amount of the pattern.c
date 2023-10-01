#include <stdio.h>
int main(){
  int n, m, c = 0;
  scanf("%d", &n);
  int a[32][32];
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      scanf("%d", &a[i][j]);
  scanf("%d", &m);
  int b[32][32];
  for(int i = 0; i < m; i++)
    for(int j = 0; j < m; j++)
      scanf("%d", &b[i][j]);
  for(int i = 0; i < n - m + 1; i++)
    for(int j = 0; j < n - m + 1; j++)
      if(a[i][j] == b[0][0]){
        for(int k = 0; k < m; k++)
          for(int l = 0; l < m; l++)
            if(b[k][l] == 1)
              if(a[i + k][j + l] != 1) goto cont;
        c++; cont:;
      }
  printf("%d\n", c);
}