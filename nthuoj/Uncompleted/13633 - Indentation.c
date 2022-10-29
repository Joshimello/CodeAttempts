#include <stdio.h>
#include <string.h>
int main(){
  while(1){
    int l = 0;
    char a[1000] = {'\0'};
    int p = 0;
    for(int i = 0;; i++){
      char t;
      if(scanf("%c", &t) == EOF) return 0;
      if(t == '\n') break;
      if(t != ';') p = 1;
      a[i] = (t == ';' && p == 0) ? ' ' : t;
      l++;
    }
    if(a[l - 1] == '{' || a[0] == '#')
      goto print;
    /*else if(a[l - 1] == '}'){
      printf("}\n");
      continue;
    }*/
    a[l] = ';';
    print: printf("%s\n", a);
  }
}