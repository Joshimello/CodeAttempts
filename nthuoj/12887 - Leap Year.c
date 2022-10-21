#include <stdio.h>
int main(){
  int y;
  scanf("%d", &y);
  printf((y%4==0&&y%100!=0)||y%400==0?"Leap year\n":"Common year\n");
}