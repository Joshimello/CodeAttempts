#include <stdio.h>

int main(void) {
  int num, a, b, c, d;

  scanf("%d", &num);

  a = num % 2;
  num /= 2;
  b = num % 2;
  num /= 2;
  c = num % 2;
  num /= 2;
  d = num % 2;

  printf("%d%d%d%d", d, c, b, a);
}