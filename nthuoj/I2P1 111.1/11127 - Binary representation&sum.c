#include <stdio.h>
int main() {
  int m, a[11], d = 0, c = 0;
  scanf("%d", &m);
  for(int i = 0; m > 0; i++){
    a[i] = m % 2;
    m /= 2;
    d++;
  }
  for(int i = 0; i < d; i++){
    if (a[i] == 0){
      a[i] = 1;
      break;
    } else {
      a[i] = 0;
      c++;
      if(i == d - 1){
        a[i + 1] = 1;
        d += 1;
        break;
      }
    }
  }
  for(int i = d - 1; i >= 0; i--)
    printf("%d", a[i]);
  printf(" %d", c);
}