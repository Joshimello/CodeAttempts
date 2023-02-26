#include <stdio.h>
#include <stdlib.h>
int sort(int *a, int *b){return *b - *a;}
int main(){
  int n, k, a[10000];
  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; i++)
    scanf("%d", &a[i]);
  qsort(a, n, 4, sort);
  long s = 0;
  for(int i = 0; i < k; i++)
    s += a[i];
  printf("%ld\n", s);
}