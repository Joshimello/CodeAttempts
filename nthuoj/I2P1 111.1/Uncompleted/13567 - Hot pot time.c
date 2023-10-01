//NOT ALL PASS 4/5
#include <stdio.h>
int main() {
  int y1, m1, d1, h1, n1, s1, y2, m2, d2, h2, n2, s2;
  scanf("%d/%d/%d %d:%d:%d\n%d/%d/%d %d:%d:%d", &y1, &m1, &d1, &h1, &n1, &s1, &y2, &m2, &d2, &h2, &n2, &s2);
  printf("%d\n", (d2-d1)*86400+(h2-h1)*3600+(n2-n1)*60+(s2-s1));
}