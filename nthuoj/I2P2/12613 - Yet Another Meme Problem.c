#include <stdio.h>
long long int a, b, b_len;
int len(int x){
  if(x) len(x / 10);
  b_len++;
}
int main(){
  scanf("%lld %lld", &a, &b);
  len(b + 1);
  printf("%lld\n", a * (b_len - 2));
}