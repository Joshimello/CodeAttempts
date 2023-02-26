#include <stdio.h>
int s = 0;
int rcr(int n){
  if(n == 0) s++;
  if(n - 2 >= 0) rcr(n - 2);
  if(n - 1 >= 0) rcr(n - 1);
}
int main(){
  int t, n;
  scanf("%d", &t);
  for(int i = 0; i < t; i++){
    scanf("%d", &n);
    rcr(n);
    printf("%d\n", s);
    s = 0;
  }
}