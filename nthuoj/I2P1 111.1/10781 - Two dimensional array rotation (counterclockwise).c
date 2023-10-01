#include <stdio.h>
#include <string.h>
int main(){
  int n, m[100][100];
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      scanf("%d", &m[i][j]);  
  int x = 0, y = n - 1;
  while(x < n){    
    int a = x, b = y;
    while(a < n && b < n){
      printf(a==n-1||b==n-1?"%d\n":"%d ", m[a][b]);
      a++; b++;
    }
    y == 0 ? x++ : y--;
  }
}