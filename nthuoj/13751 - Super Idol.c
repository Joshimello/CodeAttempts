#include <stdio.h>
int main() {
  int t;
  scanf("%d", &t);
  while(t--){
    int n, m;
    scanf("%d %d", &n, &m);
    while(m > n) m = m & (m-1);
    printf("%d\n", m);
  }
}