#include <stdio.h>
int main() {
  int x, y;
  scanf("%d.%d", &x,&y);
  int a = x+y, b = x*10+y;
  if(b / 1000 >= 1){
    a += 1;
    b -= 1000;
  }
  printf("%d.%03d", a, b);
}