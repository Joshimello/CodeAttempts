#include <stdio.h>
#include <string.h>
int main(){
  char a[1001];
  while(scanf("%s", &a) != EOF){
    float s = 0, l = strlen(a);
    for(int i = 0; i < l; i++){
      int c = 0;
      for(int j = 0; a[i+j] == a[i]; j++) c++;
      if('0' <= a[i] && a[i] <= '9'){
        printf("%d'%c'", c, a[i]);
        s += 4;
      }
      else{
        printf("%d%c", c, a[i]);
        s += 2;
      }
      for(int j = c / 10; j > 0; j /= 10) s++;
      i += c - 1;
    }
    if(s < l)
      printf("\ncompress rate:%6.3f\n", s / l);
    else
      printf("\nthe string can't zip\n");
  }
}