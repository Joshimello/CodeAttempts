#include <stdio.h>
int main(){
  int n;
  scanf("%d", &n);
  int t = n;
  if(n == 1) printf("1");
  while(n != 1)
    for(int i = 2; i <= n; i++)
      if(n % i == 0){
        printf(n==t?"%d":"*%d", i);
        n /= i;
        break;
      }
  printf("\n");
}