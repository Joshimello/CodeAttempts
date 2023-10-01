#include <stdio.h>

int main(void) {
  long g, b, s;
  scanf("%ld %ld %ld", &g, &b, &s);

  printf("%ld\n", g * b);
  printf("%.2f\n", (float)g / (float)s);
}