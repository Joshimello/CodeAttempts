#include <stdio.h>
int ans;
int find(int d){
  if(d == -1) return 1;
  char n = getchar();
  if(n == EOF){
    printf("Domo");
    exit(0);
  }
  if(n == '1')
    ans += (1<<d)*(1<<d);
  if(n == '2')
    for(int i = 0; i < 4; i++)
      find(d-1);
}
int main(){
  int depth;
  scanf("%d", &depth);
  getchar();
  find(depth);
  int test = getchar(); 
  if(test >= '0' && test <= '9') printf("Domo");
  else printf("%d", ans);
}