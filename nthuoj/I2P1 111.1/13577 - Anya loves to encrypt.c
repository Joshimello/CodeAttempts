#include <stdio.h>

int main(void) {
  char str[5];
  scanf("%c%c%c%c%c", &str[0], &str[1], &str[2], &str[3], &str[4]);

  for (int i = 0; i < 5; i++)
    printf("%c", 26 - (str[i] - 'a') + 64);

  printf("\n");
}