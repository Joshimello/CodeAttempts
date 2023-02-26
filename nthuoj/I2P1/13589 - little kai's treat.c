#include <stdio.h>
int main() {
  int n;
  while(scanf("%d", &n) != EOF){
    int m = n, s = 0;
    while(m != 0){
      s += (m % 10) * (m % 10) * (m % 10);
      m /= 10;
    }
    printf(s == n?"Yes it is.\n":"No it is not.\n");
  }
}