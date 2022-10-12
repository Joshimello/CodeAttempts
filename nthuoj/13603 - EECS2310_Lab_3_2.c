#include <stdio.h>
int main(){
  int m, d, c = 0, a[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  scanf("%d/%d", &m, &d);
  if(m > 12 || m < 1 || d > a[m] || d < 1){
    printf("Input Error\n");
    return 0;
  }
  for(int i = 0; i < m; i++)
    c += a[i];
  c += d;
  if(c == 1) printf("There is 1 day\n");
  else printf("There are %d days\n", c);
}