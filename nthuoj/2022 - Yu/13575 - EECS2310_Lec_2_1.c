// Dont know question
#include <stdio.h>

int main(void) {
  float a, b;
  scanf("%f %f", &a, &b);
  if (a < b)
    printf("%f < %f\n", a, b);
  else if (b > a)
    printf("%f > %f\n", a, b);
  else
    printf("%f = %f\n", a, b);
}