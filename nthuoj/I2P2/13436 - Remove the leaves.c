#include <stdio.h>

typedef struct _node {
  int val;
  struct _node * next;
} node;

int main(){
  int n, k;
  scanf("%d %d", &n, &k);

  node list[n + 1];
  for(int i = 1; i <= n; i++){
    list[i].val = i;
    list[i].next = NULL;
  }

  for(int i = 0; i < n-1; i++){
    int a, b;
    scanf("%d %d", a, b);

    list[i]
  }

}