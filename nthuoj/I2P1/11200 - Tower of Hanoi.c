#include <stdio.h>
int hanoi(int n){
  if(n == 0) return;
  hanoi(n-1);
  printf("%d\n", n);
  hanoi(n-1);
}
int main(){
  int n;
  scanf("%d", &n);
  hanoi(n);
}