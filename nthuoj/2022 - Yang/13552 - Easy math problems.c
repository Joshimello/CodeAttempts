#include <stdio.h>
int main(void)
{
  char oper;
  float x, y;
  scanf("%f %c %f", &x, &oper, &y);

  switch (oper) {
    case '+': printf("%.3f", x + y);
    case '-': printf("%.3f", x - y);
    case '*': printf("%.3f", x * y);
    case '/': printf("%.3f", x / y);
  }
  
  printf("\n");
}