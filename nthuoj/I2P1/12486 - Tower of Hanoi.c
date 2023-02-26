#include <stdio.h>
void h(int n, char a, char b, char c){
  if(n==0) return;
  h(n-1, a, c, b);
  printf("move disk %d from rod %c to rod %c\n", n, a, c);
  h(n-1, b, a, c);
}
int main(){
  int n;
  scanf("%d", &n);
  h(n, 'A', 'B', 'C');
}