#include <stdio.h>
int main() {
  char a, b, c;
  long n;
  scanf("%c%c%c %ld", &a, &b, &c, &n);

  if (n < 0)
    n = 26 + (n % 26);
  
  a = (a - 'A' + n) % 26 + 'A';
  b = (b - 'A' + n) % 26 + 'A';
  c = (c - 'A' + n) % 26 + 'A';
  
  printf("%c%c%c\n", a, b, c);
}