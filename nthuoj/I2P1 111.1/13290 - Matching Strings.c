#include <stdio.h>
#include <string.h>
int main(){
  int n, m; char a[101][1001], t[1001];
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++){
    scanf("%s", &a[i]);
  }
  for(int i = 0; i < m; i++){
    scanf("%s", &t);
    for(int j = 0; j < n; j++)
      if(strcmp(t, a[j]) == 0){
        printf("Yes\n");
        goto cont;
      }
    printf("No\n");
    cont:;
  }
}