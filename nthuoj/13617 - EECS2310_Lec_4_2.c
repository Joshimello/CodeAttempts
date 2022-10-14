//correct but no pass
#include <stdio.h>
int main(){
  char c;
  int n = 0, a[32];
  while(1){
    scanf("%c", &c);
    if(c == 10) break;
    a[n] = c;
    n++;
  }
  for(int i = 0; i < n / 2 + 1; i++)
    if(a[i] != a[n - i - 1]) goto not;
  printf("a palindrome\n"); return;
  not: printf("not a palindrome\n");
}