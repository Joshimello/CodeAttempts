#include <stdio.h>
int h, w, ans;
char key[100][100], hole[100][100];
int check(){
  for(int i = 0; i < h; i++)
    for(int j = 0; j < w; j++)
      if(key[i][j] != hole[i][j]) return 0;
  return 1;
}
void swap(int x, int y, int xx, int yy){
  char t = key[x][y];
  key[x][y] = key[xx][yy];
  key[xx][yy] = t;
}
void find(int x, int y, int k){
  if(k == 0){
    if(check()) ans++;
    return;
  }

  // debug uwu
  // for(int i = 0; i < h; i++)
  //   for(int j = 0; j < w; j++)
  //     printf(j<w-1?"%c ":"%c\n", key[i][j]);
  // printf("[%d %d]\n", x, y);

  if(x+1<h&&y+1<w){
    swap(x, y, x+1, y+1);
    find(x+1, y+1, k-1);
    swap(x, y, x+1, y+1);
  }
    
  if(x-1>=0&&y+1<w){
    swap(x, y, x-1, y+1);
    find(x-1, y+1, k-1);
    swap(x, y, x-1, y+1);
  }
  
  if(x+1<h&&y-1>=0){
    swap(x, y, x+1, y-1);
    find(x+1, y-1, k-1);
    swap(x, y, x+1, y-1);
  }
    
  if(x-1>=0&&y-1>=0){
    swap(x, y, x-1, y-1);
    find(x-1, y-1, k-1);
    swap(x, y, x-1, y-1);
  }
  
  return;
}
int main(){
  int k, x, y;
  scanf("%d %d %d", &h, &w, &k);
  for(int i = 0; i < h; i++)
    for(int j = 0; j < w; j++){
      scanf(" %c", &key[i][j]);
      if(key[i][j] == 'x'){x=i; y=j;}
    }
  for(int i = 0; i < h; i++)
    for(int j = 0; j < w; j++)
      scanf(" %c", &hole[i][j]);
  find(x, y, k);
  printf("%d\n", ans);
}