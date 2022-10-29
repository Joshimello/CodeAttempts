#include <stdio.h>
#include <string.h>
int main(){
  char a[100000];
  while(scanf("%s", &a) != EOF){
    int l = strlen(a);
    for(int i = 0; i < l / 2 + 1; i++)
      if(a[i] != a[l - i - 1]) goto no;
    printf("Yes\n"); continue;
    no: printf("No\n");
  }
}