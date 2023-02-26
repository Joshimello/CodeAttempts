#include <stdio.h>
char a[3][3], b[3][3];
int check(){
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++)
      if(a[i][j] != b[i][j]) return 0;
  return 1;
}
void swap(int fx, int fy, int tx, int ty){
  char t = a[fx][fy];
  a[fx][fy] = a[tx][ty];
  a[tx][ty] = t;
}
int find(int x, int y, int k){
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++)
      printf(j<2?"%c ":"%c\n", a[i][j]);
  printf("\n");

  if(check()){
    printf("OK\n");
    return 1;
  }
  else if(k == 0){
    printf("NYAAA\n");
    return 0;
  } 
  
  if(x+1 < 3){
    printf("%d down\n", k);
    swap(x, y, x+1, y);
    if(find(x+1, y, k-1)) return 1;
    else swap(x, y, x+1, y);
  }
  if(x-1 >= 0){
    printf("%d up\n", k);
    swap(x, y, x-1, y);
    if(find(x-1, y, k-1)) return 1;
    else swap(x, y, x-1, y);
  }
  if(y+1 < 3){
    printf("%d right\n", k);
    swap(x, y, x, y+1);
    if(find(x, y+1, k-1)) return 1;
    else swap(x, y, x, y+1);
  }
  if(y-1 >= 0){
    printf("%d left\n", k);
    swap(x, y, x, y-1);
    if(find(x, y-1, k-1)) return 1;
    else swap(x, y, x, y-1);
  }

  return 0;
}
int main(){
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++)
      scanf(" %c", &a[i][j]);
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++)
      scanf(" %c", &b[i][j]);
  find(1, 2, 5);
}