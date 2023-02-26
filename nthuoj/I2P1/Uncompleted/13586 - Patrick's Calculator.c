#include <stdio.h>
int main(){
  int a[34], t, l = 0; char c; a[0] = 0;
  for(int i = 1; c != 10; i++)
    scanf("%d%c", &a[i], &c);
  c = ' ';
  for(int i = 1; c != 10; i++){
    scanf("%d%c", &t, &c);
    a[i] += t;
    l++;
  }
  for(int i = l; i >= 0; i--){
    if(a[i] > 1000){
      a[i] -= 1000;
      a[i - 1] += 1;
    }
  }
  for(int i = 1; i <= l; i++)
    printf(i<l?"%03d,":"%03d\n", a[i]);
}