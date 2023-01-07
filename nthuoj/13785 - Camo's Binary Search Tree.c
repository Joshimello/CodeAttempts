#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  int val;
  struct node *left, *right;
} Node;

void Insert(Node **root, int src) {
  if (*root == NULL) {
    *root = (Node *)malloc(sizeof(Node));
    (*root)->val = src;
    (*root)->left = (*root)->right = NULL;
  } else if (src < (*root)->val) {
    Insert(&((*root)->left), src);
  } else if (src > (*root)->val) {
    Insert(&((*root)->right), src);
  }
}

void Printt(Node *root, int d) {
  if (root == NULL)
    return;
  printf(!d ? "%d" : " %d", root->val);
  Printt(root->left, d + 1);
  Printt(root->right, d + 1);
}

void Print(Node *root) {
  Printt(root, 0);
  printf("\n");
}

int main() {

  char str[50];

  Node *root = NULL;

  while (scanf("%s", str) != EOF) {
    if (!strcmp(str, "Insert")) {
      int num;
      scanf("%d", &num);

      Insert(&root, num);
    } else if (!strcmp(str, "Print")) {
      Print(root);
    }
  }
}