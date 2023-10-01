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
#include <stdio.h>
#include <string.h>

// header.h
#include <stdlib.h>

typedef struct node {
    int idx;
    struct node *next;
  } Node;

  void AddFront(Node * *head, Node * *back, int num) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->idx = num;
    new_node->next = *head;
    *head = new_node;
  }

  void AddBack(Node * *head, Node * *back, int num) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->idx = num;
    new_node->next = NULL;
    (*back)->next = new_node;
    *back = new_node;
  }

  void DeleteFront(Node * *head, Node * *back) {
    if (*head == *back)
      return;
    Node *del_node = *head;
    *head = (*head)->next;
    free(del_node);
  }

  void Delete(Node * *head, Node * *back, int value) {
    Node *curr = *head;
    Node *prev = NULL;
    while (curr != NULL) {
      if (curr->idx == value) {
        if (prev == NULL) {
          *head = curr->next;
        } else {
          prev->next = curr->next;
        }
        if (curr == *back) {
          *back = prev;
        }
        Node *del_node = curr;
        curr = curr->next;
        free(del_node);
      } else {
        prev = curr;
        curr = curr->next;
      }
    }
  }

  void Swap(Node * *head, Node * *back) {
    if (*head == *back)
      return; // list is empty or has only one element
    Node *prev = NULL;
    Node *curr = *head;
    Node *next;

    while (curr != NULL) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }

    *back = *head;
    *head = prev;
  }

  // main.c
  int main() {
    char str[50];

    Node *head = (Node *)malloc(sizeof(Node));
    Node *back = head;
    // initialize the dummy head

    // we'll append the element after this dummy head to avoid runtime error.
    head->idx = -1;
    head->next = NULL;

    while (scanf("%s", str) != EOF) {

      int num;

      if (!strcmp(str, "AddFront")) {
        scanf("%d", &num);
        AddFront(&head, &back, num);
      } else if (!strcmp(str, "AddBack")) {
        scanf("%d", &num);
        AddBack(&head, &back, num);
      } else if (!strcmp(str, "DeleteFront")) {
        DeleteFront(&head, &back);
      } else if (!strcmp(str, "Delete")) {
        scanf("%d", &num);
        Delete(&head, &back, num);
      } else if (!strcmp(str, "Swap")) {
        Swap(&head, &back);
      }
    }

    // print all the element except the dummy head and free them.
    Node *print = head;

    if (head->next == NULL)
      printf("empty\n");

    while (print != NULL) {
      if (print->idx != -1)
        printf("%d%c", print->idx, (print->next == NULL ? '\n' : ' '));

      Node *del = print;
      print = print->next;
      free(del);
    }
  }

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