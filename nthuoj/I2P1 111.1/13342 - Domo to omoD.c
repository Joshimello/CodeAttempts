#include <stdio.h>
char a[500]; int i = 0;
void find(){
  char c;
  scanf(" %c", &c);
  if(c >= '0' && c <= '9')
    a[i++] = c;
  else{
    find();
    find();
    a[i++] = c;
  }
}
int main(){
  find();
  for(int j = 0; j < i; j++)
    printf(j<i-1?"%c ":"%c", a[j]);
}