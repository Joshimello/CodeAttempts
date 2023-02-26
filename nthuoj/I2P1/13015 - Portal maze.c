#include <stdio.h>
int h, w, found = 0, tpx[26], tpy[26]; char m[300][300];
void find(int x, int y){
  if(m[x][y] == '&'){ found = 1; return; }
  if(m[x][y] >= 'a' && m[x][y] <= 'z'){
    int alpha = m[x][y]-'a';
    m[x][y] = '#';
    x = tpx[alpha];
    y = tpy[alpha];
  }
  m[x][y] = '#';
  // debug uwu
  // for(int i = 0; i < h; i++)
  //   for(int j = 0; j < w; j++)
  //     printf(j<w-1?"%c":"%c\n", m[i][j]);
  // printf("\n");
  if(x+1 < h && m[x+1][y] != '#') find(x+1, y);
  if(x-1 >= 0 && m[x-1][y] != '#') find(x-1, y);
  if(y+1 < w && m[x][y+1] != '#') find(x, y+1);
  if(y-1 >= 0 && m[x][y-1] != '#') find(x, y-1);
}
int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    found = 0;
    int sx, sy;
    scanf("%d %d", &h, &w);
    for(int i = 0; i < h; i++)
      for(int j = 0; j < w; j++){
        scanf(" %c", &m[i][j]);
        if(m[i][j] == '$'){ sx = i; sy = j; }
        if(m[i][j] >= 'A' && m[i][j] <= 'Z'){
          tpx[m[i][j]-'A'] = i;
          tpy[m[i][j]-'A'] = j;
        }
      }
    find(sx, sy);
    printf(found?"Yes\n":"No\n");
  }
}