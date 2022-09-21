#include <stdio.h>

int main(void) {
  int inInt;
  int outBin[32];
  int i = 0;

  scanf("%d", &inInt);

  while (inInt > 0) {
    outBin[i] = inInt % 2;
    inInt = inInt / 2;
    i++;
  }

  for (int j = i - 1; j >= 0; j--)
    printf("%d", outBin[j]);
  printf("\n");
}