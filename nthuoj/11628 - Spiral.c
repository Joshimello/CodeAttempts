#include <stdio.h>
int main(){
  int t;
  scanf("%d", &t);
  while(t > 0){
    int n, x = 0, y = -1, r = 0;
    scanf("%d", &n);
    char a[n][n];
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
        a[i][j] = ' ';
    for(int i = n; i > 0; i--){
      if(r % 4 == 0)
        for(int j = 1; j <= i; j++){
          y++;
          a[x][y] = '#';
        }
      if(r % 4 == 1)
        for(int j = 1; j <= i; j++){
          x++;
          a[x][y] = '#';
        }
      if(r % 4 == 2)
        for(int j = 1; j <= i; j++){
          y--;
          a[x][y] = '#';
        }
      if(r % 4 == 3)
        for(int j = 1; j <= i; j++){
          x--;
          a[x][y] = '#';
        }
      r++;
    }
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++)
        printf("%c", a[i][j]);
      printf("\n");
    }
    t--;
  }
}