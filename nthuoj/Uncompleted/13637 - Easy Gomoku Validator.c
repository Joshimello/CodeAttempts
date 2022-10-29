// cannot detect alternating positions
#include <stdio.h>
int main(){
  int n, x, y, p = 1, a[15][15] = {0};
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d %d", &x, &y);
    a[x - 1][y - 1] = p;
    int t = 0, tr = 0, r = 0, br = 0, b = 0, bl = 0, l = 0, tl = 0;
    for(int j = 0; j < 5; j++)
      if(a[x - j - 1][y - 1] == p && x-j-1>=0 && x-j-1<15 && y-1>=0 && y-1<15) t++;
    for(int j = 0; j < 5; j++)
      if(a[x - j - 1][y + j - 1] == p && x-j-1>=0 && x-j-1<15 && y+j-1>=0 && y+j-1<15) tr++;
    for(int j = 0; j < 5; j++)
      if(a[x - 1][y + j - 1] == p && x-1>=0 && x-1<15 && y+j-1>=0 && y+j-1<15) r++;
    for(int j = 0; j < 5; j++)
      if(a[x + j - 1][y + j - 1] == p && x+j-1>=0 && x+j-1<15 && y+j-1>=0 && y+j-1<15) br++;
    for(int j = 0; j < 5; j++)
      if(a[x + j - 1][y - 1] == p && x+j-1>=0 && x+j-1<15 && y-1>=0 && y-1<15) b++;
    for(int j = 0; j < 5; j++)
      if(a[x + j - 1][y - j - 1] == p && x+j-1>=0 && x+j-1<15 && y-j-1>=0 && y-j-1<15) bl++;
    for(int j = 0; j < 5; j++)
      if(a[x - 1][y - j - 1] == p && x-1>=0 && x-1<15 && y-j-1>=0 && y-j-1<15) l++;
    for(int j = 0; j < 5; j++)
      if(a[x - j - 1][y - j - 1] == p && x-j-1>=0 && x-j-1<15 && y-j-1>=0 && y-j-1<15) tl++;
    
    for(int j = 0; j < 15; j++)
      for(int k = 0; k < 15; k++)
        printf(k<14?"%d ":"%d\n", a[j][k]);
    printf("%d %d %d %d %d %d %d %d\n", t, tr, r, br, b, bl, l, tl);
    if(t==5||tr==5||r==5||br==5||b==5||bl==5||l==5||tl==5){
      printf("%s wins at the %dth step.\n", p==1?"LCS":"TSC", i + 1);
      return 0;
    }
    p = p == 1 ? 2 : 1;
  }
  printf("There's no winner.\n");
}