#include <stdio.h>
#include <string.h>
int l, s = 0; char c[50];
int can(int str, int end){
  while(str <= end){
    if(c[str] != c[end]) return 0;
    str++; end--;
  }
  return 1;
}
void find(int index){
  if(index == l){ s++; return; }
  for(int i = index+1; i <= l; i++)
    if(can(index, i-1)) find(i);
}
int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    scanf("%s", c);
    s = 0;
    l = strlen(c);
    find(0);
    printf("%d\n", s);
  }
}