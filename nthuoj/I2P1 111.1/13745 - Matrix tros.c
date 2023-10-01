#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// header.h
int cmp(int *a, int *b){return *a - *b;}
int** s(int* a,int len){
  qsort(a, len, sizeof(int), cmp);
  // for(int i = 0; i < len; i++)
  //   printf("%d ", a[i]);
  // printf("\n");

  int n = (int)sqrt(len);
  
  int **arr = malloc(n * sizeof(int*));
  for(int j = 0; j < n; j++)
    arr[j] = malloc(n * sizeof(int));

  int i = 0;
  for(int j = 0; j < n; j++)
    for(int k = 0; k < n; k++)
      arr[j][k] = a[i++];
  
  return arr;
}
void print(int** ans,int len){
  int n = (int)sqrt(len);
  for(int j = 0; j < n; j++)
    for(int k = 0; k < n; k++)
      printf(k<n-1?"%d":"%d\n", ans[j][k]);
}

// main.c
int main() {
	int len;
	int **ans;	
	scanf("%d", &len);
	int *a = (int*)malloc(len * sizeof(int));
	for (int i = 0;i < len;i++) scanf("%d", &a[i]);
	ans = s(a,len);
	print(ans,len);
	free(a);
	return 0;
}