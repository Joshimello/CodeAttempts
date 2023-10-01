#include <stdio.h>
#include <stdlib.h>
int cmp(int *a, int *b){ return *a - *b; }
void array2d_sort(int n, int m, long long a[][500]){
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      int si = i, sj = j, ei = i, ej = j;
      while (si > 0 && sj > 0){ si--; sj--; }
      while (ei < n-1 && ej < m-1){ ei++; ej++; }
      int l = ei-si+1, dia[l];
      for(int k = 0; k < l; k++)
        dia[k] = a[si+k][sj+k];
      qsort(dia, l, sizeof(int), cmp);
      for(int k = 0; k < l; k++)
        a[si+k][sj+k] = dia[k];
    }
  }
}