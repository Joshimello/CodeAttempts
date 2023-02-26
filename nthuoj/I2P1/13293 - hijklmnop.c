#include <stdio.h>
int main(){
  char a[9], b[123];
  for(int i = 0; i < 9; i++){
    scanf(" %c", &a[i]);
    b[a[i]] = i + 1;
  }
  for(int i = 0; i < 4; i++){
    char c;
    scanf(" %c", &c);
    if(c<58) printf("%c", a[c - '1']);
    else printf("%d", b[c]);
  }
}