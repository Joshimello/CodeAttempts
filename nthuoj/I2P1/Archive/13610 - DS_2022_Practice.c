#include <stdio.h>
int main(){
  int a = -1e9, b = 1e9, n; 
  char t;
  long s = 0;
  while(t != 10){
    scanf("%d%c", &n, &t);
    if(n > a) a = n;
    if(n < b) b = n;
    s += n;
  }
  printf("%d %d %ld\n", a, b, s);
}