#include <stdio.h>
int main() {
  int n;
  scanf("%d", &n);
  for(int i = n; i > 0; i--){
    for(int j = i - 1; j > 0; j--)
      printf(" ", j);
    for(int j = 1; j <= n - i + 1; j++)
      printf("%d", j);
    for(int j = n - i; j > 0; j--)
      printf("%d", j);
    printf("\n");
  }
  for(int i = 0; i < n - 1; i++){
    for(int j = i + 1; j > 0; j--)
      printf(" ", j);
    for(int j = 1; j <= n - i - 1; j++)
      printf("%d", j);
    for(int j = n - i - 2; j > 0; j--)
      printf("%d", j);
    printf("\n");
  }
}