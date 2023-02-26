#include <stdio.h>
int main(){
  int s[5], u[5] = {0}; char a[5], b[5], t;
  for(int i = 0; i < 10; i++){
    scanf(" %c", &t);
    if(i < 5) a[i] = t<91?t+32:t;
    else b[i - 5] = t<91?t+32:t;
  }
  for(int i = 0; i < 5; i++){
    s[i] = b[i] - a[i];
    if(s[i] < 0) s[i] += 26;
  }
  for(int i = 0; i < 5; i++){
    char c;
    scanf(" %c", &c);
    if(c <= 'Z') c += c + s[i] > 'Z' ? s[i] - 26 + 32 : s[i] + 32;
    else c += c + s[i] > 'z' ? s[i] - 26 - 32 : s[i] - 32;
    printf(i<4?"%c":"%c\n", c);
  }
}