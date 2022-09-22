#include <stdio.h>
int main(void)
{
  char oper;
  float x, y;
  scanf("%f %c %f", &x, &oper, &y);

  if (oper == '+')
    printf("%.3f", x + y);
  else if (oper == '-')
    printf("%.3f", x - y);
  else if (oper == '*')
    printf("%.3f", x * y);
  else if (oper == '/')
    printf("%.3f", x / y);

  printf("\n");
}