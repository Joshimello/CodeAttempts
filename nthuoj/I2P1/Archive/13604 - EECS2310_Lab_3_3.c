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
  if(c % 7 == 4) printf("Monday\n");
  if(c % 7 == 5) printf("Tuesday\n");
  if(c % 7 == 6) printf("Wednesday\n");
  if(c % 7 == 0) printf("Thursday\n");
  if(c % 7 == 1) printf("Friday\n");
  if(c % 7 == 2) printf("Saturday\n");
  if(c % 7 == 3) printf("Sunday\n");
}