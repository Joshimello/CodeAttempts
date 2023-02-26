#include <stdio.h>
int main(void) {
  int a;
  scanf("%d", &a);
  if ((a % 4 == 0 && a % 100 != 0) || a % 400 == 0)
    printf("a leap year");
  else
    printf("not a leap year");
}