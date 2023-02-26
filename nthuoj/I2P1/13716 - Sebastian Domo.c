#include <stdio.h>
int h, w, path[20][20];
void find(int x, int y, int t){
  if(path[x][y] <= t) return;
  path[x][y] = t;
  
  // printf("[%d %d]\n", x, y);
  // for(int i = 0; i < h; i++)
  //   for(int j = 0; j < w; j++)
  //     printf(j<w-1?"%d ":"%d\n", path[i][j]);
  // printf("\n");
  
  if(x+1 < h) find(x+1, y, t+1);
  if(x-1 >= 0) find(x-1, y, t+1);
  if(y+1 < w) find(x, y+1, t+1);
  if(y-1 >= 0) find(x, y-1, t+1);
}
int main(){
  char temp;
  int q, a[4], diff = 1e9, ex, ey;
  scanf("%d %d %d", &h, &w, &q);
  for(int i = 0; i < h; i++)
    for(int j = 0; j < w; j++){
      scanf(" %c", &temp);
      if(temp == '-'){ex = i; ey = j;}
      if(temp == 'X'){path[i][j] = -1;}
      else path[i][j] = 1e9;
    }
  
  for(int i = 0; i <= q; i++){
    for(int i = 0; i < h; i++)
      for(int j = 0; j < w; j++)
        if(path[i][j] != -1) path[i][j] = 1e9;
    int x, y;
    scanf("%d %d", &x, &y);
    find(x, y, 0);
    printf(i<q?"%d ":"%d\n", path[ex][ey]);
    a[i] = path[ex][ey];

    if(i == 0) continue;
    if(a[i]-a[0] < diff) diff = a[i]-a[0];
  }
  printf("%d\n", diff);
}