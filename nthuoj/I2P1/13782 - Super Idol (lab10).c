#include <stdio.h>
int main() {
  int t;
  scanf("%d", &t);
  while(t--){
    int a, b;
    scanf("%d %d", &a, &b);
    while(b > a) b = b & (b-1);
    printf("%d\n", b);
  }
}