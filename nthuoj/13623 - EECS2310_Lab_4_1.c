#include <stdio.h>
int main(){
  int c = 0, a[32];
  for(int i = 0;; i++){
    scanf("%d", &a[i]);
    if(a[i] == -1) break;
  }
  for(int i = 0;; i++){
    if(a[i] == -1) break;
    for(int j = i;; j++){
      if(a[j] == -1) break;
      if(a[i] > a[j]){
        printf(c<1?"%d>%d":", %d>%d", a[i], a[j]);
        c++;
      }
    }
  }
  printf(c>0?"\n%d inversion(s)\n":"%d inversion(s)\n", c);
}