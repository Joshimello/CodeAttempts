#include <stdio.h>
int n, m, c = 0, a[1000][1000];
int find(int x, int y, int c){
  a[x][y] = c;
  if(a[x+1][y] > c+1 && x+1 < n) find(x+1, y, c+1);
  if(a[x-1][y] > c+1 && x-1 >= 0) find(x-1, y, c+1);
  if(a[x][y+1] > c+1 && y+1 < m) find(x, y+1, c+1);
  if(a[x][y-1] > c+1 && y-1 >= 0) find(x, y-1, c+1);
}
int main(){
  int sx, sy, mx, my;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++){
      char t;
      scanf(" %c", &t);
      if(t == 'S'){sx = i; sy = j;}
      if(t == 'M'){mx = i; my = j;}
      if(t == 'o' || t == '^'){a[i][j] = -1;}
      else{a[i][j] = m*n+1;}
    }
  find(sx, sy, c);
  printf("%d\n", a[mx][my]);
}