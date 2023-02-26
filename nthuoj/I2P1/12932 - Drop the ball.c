#include <stdio.h>
int main() {
  int m, n, q, p;
  scanf("%d %d", &m, &n);
  char a[m][n];
  for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++)
      scanf(" %c", &a[i][j]);
  scanf("%d", &q);
  for(int i = 0; i < q; i++){
    scanf("%d", &p);
    int x = 0, y = p - 1;
    while(x < m){
      if(a[x][y] == '\\'){
        if(y == n - 1) goto right;
        if(a[x][y+1] == '/') goto stuck;        
        x++; y++;
      }
      if(a[x][y] == '/'){
        if(y == 0) goto left;
        if(a[x][y-1] == '\\') goto stuck;
        x++; y--;
      }
    }
    printf("Position: %d\n", y + 1); continue;
    stuck: printf("Stuck QQ\n"); continue;
    right: printf("Right!\n"); continue;
    left: printf("Left!\n"); continue;
  }
}