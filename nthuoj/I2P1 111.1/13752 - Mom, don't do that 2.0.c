#include <stdio.h>
#include <string.h>
int main(){
  char a[1000000]; a[0] = '0';
  int n, k;
  scanf("%d %d", &n, &k);
  while(n--){
    int l = strlen(a);
    a[l] = '1';
    for(int i = l-1, j = 1; i >= 0; i--, j++)
      a[l+j] = a[i] == '0'?'1':'0';
  }
  while(k--){
    int t;
    scanf("%d", &t);
    printf("%c\n", a[t]);
  }
}