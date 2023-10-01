#include <stdio.h>
int main(){
  int n, x, m, m2;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d", &x);
    if(i == 0) m = x;
    else if(i == 1){
      if(x > m){
        m2 = m;
        m = x;
      }
      else m2 = x;
    }
    else if(x >= m){
      m2 = m;
      m = x;
    }
    else if(x >= m2 && x < m) m2 = x;
    printf(i==0?"0":" %d", m2);
  }
  printf("\n");
}