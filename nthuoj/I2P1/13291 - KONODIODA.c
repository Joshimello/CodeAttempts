#include <stdio.h>
int main(){
  int m, n;
  scanf("%d %d", &m, &n);
  while(m--){
    int k, c = 0, row[2049] = {0}, col[2049] = {0}, dia[4098] = {0}, dib[4098] = {0};
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++){
        scanf("%d", &k);
        if(k == 255){
          row[i]++;
          col[j]++;
          dia[i + j]++;
          dib[i - j + n - 1]++;
        }
      }
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++){
        int a = i+j >= n ? (n-1)*2 - (i+j) + 1 : i+j+1;
        int b = i-j > 0 ? n-(i-j) : n+(i-j);
        if(row[i] == n && col[j] == n && dia[i+j] == a && dib[i-j+n-1] == b) c++;
      } 
    printf("%d\n", c);
  }
}