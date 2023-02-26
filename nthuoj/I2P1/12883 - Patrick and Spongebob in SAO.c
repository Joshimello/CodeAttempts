#include <stdio.h>
int main() {
  int n, order[500];
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &order[i]);
  }
  int m;
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    int start, end;
    scanf("%d %d", &start, &end);

    int max = 0, ans;
    for (int j = start - 1; j < end; j++) {
      int count = 0;
      for (int k = start - 1; k < end; k++) {
        if (order[j] == order[k])
          count++;
      }
      if (count > max) {
        max = count;
        ans = order[j];
      }
      if (count == max && order[j] < ans) {
        ans = order[j];
      }
    }
    printf("%d\n", ans);
  }
}