#include <stdio.h>
int main() {
  int x, a, b, c;
  scanf("%d", &x);
  a = (x % 10) % 2 == 0 ? 'E' : 'F'; x /= 10;
  b = (x % 10) % 2 == 0 ? 'C' : 'D'; x /= 10;
  c = (x % 10) % 2 == 0 ? 'A' : 'B';
  printf("%c%c%c", c, b, a);
}