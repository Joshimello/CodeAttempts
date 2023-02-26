#include <stdio.h>

int main(void) {
  int price, one, five, ten, fifty;
  int count = 0;
  scanf("%d %d %d %d %d", &price, &one, &five, &ten, &fifty);

  while (price >= 50 && fifty != 0) {
    price -= 50;
    fifty--;
    count++;
  }

  while (price >= 10 && ten != 0) {
    price -= 10;
    ten--;
    count++;
  }

  while (price >= 5 && five != 0) {
    price -= 5;
    five--;
    count++;
  }

  while (price >= 1 && one != 0) {
    price -= 1;
    one--;
    count++;
  }

  if (price != 0) {
    count = -1;
  }

  printf("%d\n", count);
}