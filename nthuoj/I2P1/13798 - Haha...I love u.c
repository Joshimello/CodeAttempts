#include <stdio.h>
#include <string.h>
#define cmp(a, b)((a > b) ? a : b)
int main(){
  char s1[3100], s2[3100];
  scanf("%s %s", &s1, &s2);
  int l1 = strlen(s1), l2 = strlen(s2);
  int a[l1+1][l2+1];
  memset(a, 0, sizeof(a));
  
  for (int i = 1; i <= l1; i++)
    for (int j = 1; j <= l2; j++){
      if (s1[i-1] == s2[j-1])
        a[i][j] = a[i-1][j-1] + 1;
      else
        a[i][j] = cmp(a[i][j-1], a[i-1][j]);
    }
  
  printf("%d\n", a[l1][l2]);
}