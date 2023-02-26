#include <stdio.h>
#include <string.h>
int main(){
  char a[100000]; int a_i = 0, c = 0;
  while(scanf("%c", &a[a_i]) != EOF) a_i++;

  char *title = strstr(a, "<title>");
  for(int i = title-a+7; a[i] != '<'; i++)
    printf("%c", a[i]);
  printf("\n");
  
  for(char *a_tag = a; a_tag = strstr(a_tag, "</a>"); ++a_tag) c++;
  printf("%d\n", c);
}