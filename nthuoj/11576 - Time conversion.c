#include <stdio.h>
int main(void)
{
  int h, m;
  scanf("%2d%2d", &h, &m);
  if (h >= 12)
    printf("%02d:%02d p.m.", h - 12, m);
  else
    printf("%02d:%02d a.m.", h, m);
}