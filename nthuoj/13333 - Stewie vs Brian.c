#include <stdio.h>
int a[9][9];
int can(int x, int y, int n){
  for(int i = 0; i < 9; i++)
    if(a[i][y] == n) return 0;
  for(int i = 0; i < 9; i++)
    if(a[x][i] == n) return 0;
  for(int i = x/3*3; i < x/3*3+3; i++)
    for(int j = y/3*3; j < y/3*3+3; j++)
      if(a[i][j] == n) return 0;
  return 1;
}
int find(){
  for(int i = 0; i < 9; i++)
    for(int j = 0; j < 9; j++)
      if(a[i][j] == 0){
        for(int k = 1; k <= 9; k++)
          if(can(i, j, k)){
            a[i][j] = k;
            if(find()) return 1;
            else a[i][j] = 0;
          }
        return 0;
      }
  return 1;
}
int main(){
  for(int i = 0; i < 9; i++)
    for(int j = 0; j < 9; j++)
      scanf("%d", &a[i][j]);
  if(find())
    for(int i = 0; i < 9; i++)
      for(int j = 0; j < 9; j++)
        printf(j<8?"%d ":"%d\n", a[i][j]);
  else printf("no solution\n");
}