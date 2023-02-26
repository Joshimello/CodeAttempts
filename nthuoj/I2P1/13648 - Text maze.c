#include <stdio.h>
int main(){
  int n, s, x, y, mode = 0;
  char a[100][100];
  scanf("%d %d %d %d", &n, &s, &x, &y);
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      scanf(" %c", &a[i][j]);
  for(int m = 0; m <= s; m++){
    int p, q;
    char c = mode == 0 ? 'z' : 'A';
    printf("%c", a[x][y]);
    for(int i = -1; i <= 1; i++)
      for(int j = -1; j <= 1; j++){
        if((i == 0 && j == 0) || a[x + i][y + j] < 65) continue;
        if(mode == 0 && a[x + i][y + j] <= c){
          c = a[x + i][y + j];
          p = x + i; q = y + j;
        }
        if(mode == 1 && a[x + i][y + j] >= c){
          c = a[x + i][y + j];
          p = x + i; q = y + j;
        }
	  }
    if(c <= 'T'){
      if(c % 5 == 4) y--;
      if(c % 5 == 3) y++;
      if(c % 5 == 2) x--;
      if(c % 5 == 1) x++;
      if(c % 5 == 0){
        mode = mode == 0 ? 1 : 0;
        x = p; y = q;
      }
    }
    else if(c <= 'Z'){
      x = p; y = q;
    }
    else if(c <= 't'){
      if(c % 5 == 2) y--;
      if(c % 5 == 3) y++;
      if(c % 5 == 4) x--;
      if(c % 5 == 0) x++;
      if(c % 5 == 1){
        mode = mode == 0 ? 1 : 0;
        x = p; y = q;
      }
    }
    else if(c <= 'z'){
      x = p; y = q;
    }
    if(x >= n || y >= n || x < 0 || y < 0) break;
    //debug uwu
    //printf("[%d %d](%c)[%d %d](%d)\n", x, y, c, p, q, mode);
  }
}