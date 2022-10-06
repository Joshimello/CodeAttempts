#include <stdio.h>
int main(){
  int n;
  scanf("%d", &n);
  if(n % 2 == 0){
    printf("Stop drawing fake diamonds!\n"); 
    return 0; 
  }
  for(int i = 1; i <= n; i+=2){
    for(int j = n/2 - i/2; j >= 1; j--)
      printf(" ");
    for(int j = 1; j <= i; j++)
      printf("*");
    printf("\n");
  }
  for(int i = n - 2; i >= 1; i-=2){
    for(int j = n/2 - i/2; j >= 1; j--)
      printf(" ");
    for(int j = 1; j <= i; j++)
      printf("*");
    printf("\n");
  }
}