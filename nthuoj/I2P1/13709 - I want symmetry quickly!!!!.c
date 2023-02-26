#include <stdio.h>
#include <string.h>
int l, max=1e9; char c[50];
int can(int str, int end){
  while(str <= end){
    if(c[str] != c[end]) return 0;
    str++; end--;
  }
  return 1;
}
void find(int index, int count){
  if(index == l){
    if(count < max) max = count;
    return;
  }
  for(int i = index+1; i <= l; i++)
    if(can(index, i-1)) find(i, count+1);
}
int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    scanf("%s", c);
    max = 1e9;
    l = strlen(c);
    find(0, 0);
    printf("%d\n", max-1);
  }
}