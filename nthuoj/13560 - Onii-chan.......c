#include <stdio.h>

int main(void) {
  int a,b,c,d,e,f;
  scanf("%d %d %d %d", &a, &b, &c, &d);

  e = (c - b * d) / (a - b);
  f = d - e;
  
  printf("%d %d", e, f);
}