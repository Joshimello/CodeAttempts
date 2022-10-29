#include <stdio.h>
#include <string.h>
int main(){
  char n[10001], c;
  int t, cur = 0, w = 0;
  scanf("%s %d", &n, &t);
  int l = strlen(n);
  while(scanf(" %c", &c) != EOF){
    if(c == n[cur]){
      if(w > 0) goto no;
      cur++;
      printf("%d\n", cur);
      if(cur == l){
        printf("DAISUKI!\n");
        return 0;
      }
    }
    else if(c == '!'){
      w = 0;
      cur = 0;
      t -= 2;
      if(t <= 0){
        printf("SAYONARA\n");
        return 0;
      }
    }
    else if(c == '/'){
      if(cur >= 0){
        if(w > 0) w--;
        else if(cur > 0) cur--;
      }
      t -= 1;
      if(t <= 0){
        printf("SAYONARA\n");
        return 0;
      }
    }
    else{
      no:
      w++;
      printf("no\n");
    }
  }
}