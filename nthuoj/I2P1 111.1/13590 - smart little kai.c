#include <math.h>
#include <stdio.h>

int main(void) {
  while (1) {
    int num, arr[32];
    if (scanf("%d", &num) == EOF) {
      break;
    }

    int i = 0, n = num;
    while (n != 0) {
      arr[i] = n % 10;
      n /= 10;
      i++;
    }

    int sum = 0;
    for (int j = i - 1; j > -1; j--)
      sum += pow(arr[j], i);

    if (num == sum)
      printf("Yes it is.\n");
    else
      printf("No it is not.\n");
  }
}