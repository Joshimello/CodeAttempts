#include <stdio.h>
#include <math.h>

int main(void) {
  
    int num, arr[32];
    scanf("%d", &num);

    int i = 0, n = num;
    while(n != 0) {
      arr[i] = n % 10;
      n /= 10;
      i++;
    }

    int sum = 0;
    for(int j = i - 1; j > -1; j--)
      sum += pow(arr[j], i);

    if(num == sum)
      printf("Yes it is.\n");
    else
      printf("No it is not.\n");
}