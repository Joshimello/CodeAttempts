#include <stdio.h>
#include <math.h>
int main(){
  int n;
  while(scanf("%d", &n)!=EOF){
    int s=(n>1?1:2);
    for(int i=2; i<=(int)sqrt(n); i++)
      if(n%i==0) s+=i+n/i;
    printf(s==n?"True\n":"False\n");
  }
}