#include <stdio.h>
#include <string.h>
int main(){
  int n; char a, b, c[123], s[1000000];
  scanf("%s\n%d", &s, &n);
  int l = strlen(s);
  for(int i = 97; i < 123; i++)
    c[i] = i;
  for(int i = 0; i < n; i++){
    scanf(" %c %c", &a, &b);
    for(int j = 97; j < 123; j++)
      if(c[j] == a) c[j] = b;
  }
  for(int i = 0; i < l; i++)
    s[i] = c[s[i]];
  printf("%s\n", s);
}