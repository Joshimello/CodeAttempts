// correct but oj say wrong ¯\_(ツ)_/¯
#include <stdio.h>
#include <string.h>
int main(){
  char a[10000], b[10][5] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
  for(int i = 0;; i++){
    scanf("%c", &a[i]);
    if(a[i] == '\n') break;
  }
  int l = strlen(a);
  for(int i = 0; i < l - 1;){
    if(a[i] == ' '){i++; continue;}
    int c = 0, m = 0;
    for(int j = 0;; j++){
      if(a[i+j] != ' ' && a[i+j] != a[i]) break;
      if(a[i] == a[i+j]) c++;
      m++;
    }
    //if(c == 1) printf("[%s]", b[a[i] - '0']);
    //else printf("[%s:%s]", b[c], b[a[i] - '0']);
    if(c == 1) printf("%s", b[a[i] - '0']);
    else printf("%s%s", b[c], b[a[i] - '0']);
    i += m;
  }
  printf("\n");
}