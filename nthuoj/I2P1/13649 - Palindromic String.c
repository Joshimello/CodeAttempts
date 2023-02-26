#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(){
  char a[10];
  scanf("%s", a);
  int l = strlen(a);
  for(int i = 0; i < l / 2 + 1; i++)
    if(toupper(a[i]) != toupper(a[l - i - 1])) goto no;
  printf("true\n"); return 0;
  no: printf("false\n");
}