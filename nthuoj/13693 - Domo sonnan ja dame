#include <stdio.h>
double find(){
  char c; double d;
  scanf(" %c", &c);
  if(c >= '0' && c <= '9'){
    ungetc(c, stdin);
    scanf("%lf", &d);
    return d;
  }
  else{
    if(c == '*') return find() * find();
    if(c == '/') return find() / find();
    if(c == '+') return find() + find();
    if(c == '-') return find() - find();
  }
}
int main(){
  printf("%.4lf\n", find());
}