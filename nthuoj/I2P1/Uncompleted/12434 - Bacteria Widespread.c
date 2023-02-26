// recursive solution TLE
#include <stdio.h>
int n, m, t;
char a[100][100];
void infect(int x, int y, int r){
  if(a[x + 1][y] != '#') a[x + 1][y] = 'F';
  if(a[x - 1][y] != '#') a[x - 1][y] = 'F';
  if(a[x][y + 1] != '#') a[x][y + 1] = 'F';
  if(a[x][y - 1] != '#') a[x][y - 1] = 'F';
  if(r > 0){
    if(a[x + 1][y] != '#') infect(x + 1, y, r - 1);
    if(a[x - 1][y] != '#') infect(x - 1, y, r - 1);
    if(a[x][y + 1] != '#') infect(x, y + 1, r - 1);
    if(a[x][y - 1] != '#') infect(x, y - 1, r - 1);
  }
}
int main(){
  int f[100][2], c = 0;
  scanf("%d %d %d", &n, &m ,&t);
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++){
      scanf(" %c", &a[i][j]);
      if(a[i][j] == 'F'){
        f[c][0] = i;
        f[c++][1] = j;
      }
    }
  for(int i = 0; i < c; i++)
    infect(f[i][0], f[i][1], t - 1);
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++)
      printf("%c", a[i][j]);
    printf("\n");
  }
}