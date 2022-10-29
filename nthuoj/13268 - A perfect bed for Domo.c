#include <stdio.h>
int main(){
  int n, l, f = 0;
  scanf("%d %d", &n, &l);
  int a[n];
  for(int i = 0; i < n; i++)
    scanf("%d", &a[i]);
  for(int i = 0; i < n - l + 1; i++){
    int s = a[i], e = a[i + l - 1], c = 0;
    for(int j = 1; j < l - 1; j++)
      if(a[i + j] > s && a[i + j] > e) c++;
    if(c == l - 2){
      for(int j = 0; j < l; j++)
        printf(j<l-1?"%d ":"%d\n", a[i + j]);
      f = 1;
    }
  }
  if(f == 0) printf("Domo\n");
}