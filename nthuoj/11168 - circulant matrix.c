#include <stdio.h>
int main() {
  int n, a[32], o = 0;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d", &a[n - 1 - i]);
  }
  for(int i = 0; i < n; i++){
    o++;
    for(int j = n - o; j < n; j++){
      printf("%2d", a[j]);
    }
    for(int j = 0; j < n - o; j++){
      printf("%2d", a[j]);
    }
    printf("\n");
  }
}