#include <stdio.h>
#include <string.h>
char a[20][100000];
void flip(int set){
  for(int i = strlen(a[set])-1, j = 0; i >= j; i--, j++){
    char c = a[set][i]=='0'?'1':'0';
    a[set][i] = a[set][j]=='0'?'1':'0';
    a[set][j] = c;
  }
}
int main(){
  int n, t;
  scanf("%d %d", &n, &t);
  a[0][0] = '0'; a[1][0] = '1';
  for(int set = 2; set <= n; set++){
    //printf("set-1: %s\n", a[set-1]);
    strcat(a[set], a[set-1]);
    strcat(a[set], "1");
    
    flip(set-1);
    //printf("fset-1: %s\n", a[set-1]);
    strcat(a[set], a[set-1]);
    flip(set-1);

    strcat(a[set], "0");
    
    flip(set-2);
    //printf("fset-2: %s\n", a[set-2]);
    strcat(a[set], a[set-2]);
    flip(set-2);
    
    //printf("%s\n", a[set]);
  }

  while(t--){
    int k;
    scanf("%d", &k);
    printf("%c\n", a[n][k]);
  }
}