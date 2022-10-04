#include <stdio.h>
#include <stdlib.h>
int main() {
  int r, c;
  scanf("%d %d", &r, &c);
  int n, min[3] = {1e9, 0, 0}, max[3] = {0, 0, 0};
  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      scanf("%d", &n);
      if(n > max[0]){
        max[0] = n;
        max[1] = i;
        max[2] = j;
      }
      if(n < min[0]){
        min[0] = n;
        min[1] = i;
        min[2] = j;
      }
    }
  }
  printf("%d %d", abs(max[1] - min[1]) + abs(max[2] - min[2]), abs(max[0] - min[0]));
}