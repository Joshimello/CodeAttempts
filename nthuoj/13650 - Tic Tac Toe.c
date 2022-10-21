#include <stdio.h>
int main(){
  char a[3][3], c;
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++)
      scanf(" %c", &a[i][j]);
  scanf(" %c", &c);
  int f = 0;
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++){
      if(a[i][j] == '-'){
        a[i][j] = c;
        int h = 1, v = 1, d = 1, b = 1; 
        for(int k = 0; k < 3; k++)
          if(a[i][k] != c) h = 0;
        for(int k = 0; k < 3; k++)
          if(a[k][j] != c) v = 0;
        for(int k = 0; k < 3; k++)
          if(a[k][2-k] != c) d = 0;
        for(int k = 0; k < 3; k++)
          if(a[2-k][k] != c) b = 0;
        if(h == 1 || v == 1 || d == 1 || b == 1){
          printf("(%d, %d)\n", i, j);
          f = 1;
        }
        a[i][j] = '-';
      }
    }
  if(f == 0) printf("none\n");
}