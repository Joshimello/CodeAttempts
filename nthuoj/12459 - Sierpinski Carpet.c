#include <stdio.h>
long long int c = 0;
int add(int n){
  if(n > 0){
    c++;
    for(int i = 0; i < 8; i++) add(n-1);
  }
}
int main(){
  int n;
  scanf("%d", &n);
  add(n);
  printf("%lld\n", c);
}