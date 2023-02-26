//first testcase wrong idk why
#include <stdio.h>
int main(){
  int n, m = 0, a[32];
  scanf("%d", &n);
  if(n < 1) return 0;
  if(n == 1) printf("1^1\n");
  for(int i = 0; n != 1; i++)
    for(int j = 2; j <= n; j++)
      if(n % j == 0){
        a[i] = j;
        n /= j;
        m++;
        break;
      }
  for(int i = 0; i < m; i++){
    int c = 0;
    for(int j = i; j < m; j++){
      if(a[i] != a[j]) break;
      c++;
    }
    printf(i<m-1?"%d^%d*":"%d^%d\n", a[i], c);
    i += c - 1;
  }
}