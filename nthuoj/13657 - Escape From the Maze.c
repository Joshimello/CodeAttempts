#include <stdio.h>
int n, m, t, sx, sy, dx, dy;
char a[1000][1000];
void find(int x, int y){
  a[x][y] = 'x';
  if(a[x+1][y] != 'x' && x+1 < n) find(x+1, y);
  if(a[x-1][y] != 'x' && x-1 >= 0) find(x-1, y);
  if(a[x][y+1] != 'x' && y+1 < m) find(x, y+1);
  if(a[x][y-1] != 'x' && y-1 >= 0) find(x, y-1);
}
int main(){
  scanf("%d %d %d", &n, &m, &t);
  while(t--){
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++){
        scanf(" %c", &a[i][j]);
        if(a[i][j] == 'S'){sx = i; sy = j;}
        if(a[i][j] == 'D'){dx = i; dy = j;}
      }
    find(sx, sy);
    printf(a[dx][dy] == 'x'?"ESCAPE!\n":"QQ\n");
  }
}