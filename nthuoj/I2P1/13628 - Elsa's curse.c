#include <stdio.h>
int ms[9], ps[9], is[9], img[407][407];
void draw(int x, int y, int n){
  if(!n) return;
  for(int i = 0; i < ms[n]; i++)
    for(int j = 0; j < ms[n]; j++)
      img[x+i][y+j] = 1;
  draw(x - ms[n-1], y - ms[n-1], n-1);
  draw(x - ms[n-1], y + ms[n], n-1);
  draw(x + ms[n], y - ms[n-1], n-1);
  draw(x + ms[n], y + ms[n], n-1);
  if(n>2){
    draw(x - ms[n-2], y + ms[n]/2 - ms[n-2]/2, n-2);
    draw(x + ms[n], y + ms[n]/2 - ms[n-2]/2, n-2);
    draw(x + ms[n]/2 - ms[n-2]/2, y - ms[n-2], n-2);
    draw(x + ms[n]/2 - ms[n-2]/2, y + ms[n], n-2);
  }
}
int main(){
  int n, x = 0, y = 0;
  scanf("%d", &n);
  for(int i = 0; i <= n; i++){
    ms[i] = i<2 ? i : ms[i-1]*2+ms[i-2];
    ps[i] = ps[i-1] + ms[i-1];
    is[i] = ps[i]*2 + ms[i];
  }
  // debug uwu
  // for(int i = 0; i <= n; i++) printf(i<n"%d ":"%d\n", ms[i]);
  // for(int i = 0; i <= n; i++) printf(i<n"%d ":"%d\n", ps[i]);
  // for(int i = 0; i <= n; i++) printf(i<n"%d ":"%d\n", is[i]);
  draw(ps[n], ps[n], n);
  for(int i = 0; i < is[n]; i++)
    for(int j = 0; j < is[n]; j++)
      printf(j<is[n]-1? img[i][j]?"#":" " : img[i][j]?"#\n":" \n");
}
