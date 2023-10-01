// #include <stdio.h>
// #include <stdlib.h>

// header.h
#include <stdio.h>
#include <stdlib.h>

typedef struct _Node{
    int val;
    struct _Node *next;
}Node;

Node* Solver(Node* head, int k) {
    Node* curr = head;
    Node* prev = NULL;

    while (curr != NULL) {
      Node* last = curr;
      Node* kk = NULL;

      for (int i = 0; i < k && curr != NULL; i++) {
        Node* next = curr->next;
        curr->next = kk;
        kk = curr;
        curr = next;
      }

      if (prev != NULL) prev->next = kk;
      else head = kk;
    
      prev = last;
    }
  
    return head;
}

// main.c
// Node* createNode(int val){
//     Node *node = (Node*)malloc(sizeof(Node));
//     node->val = val;
//     node->next = NULL;
//     return node;
// }
// void printList(Node* head)
// {
//     while(head != NULL)
//     {
//         printf("%d ", head->val);
//         head = head->next;
//     }
// }

// int main()
// {
//     Node* head = NULL;
    
//     int tmp;
//     scanf("%d", &tmp);
//     head = createNode(tmp);
//     Node* tail = head;
    
//     while(1)
//     {
//         scanf("%d", &tmp);
//         if(tmp==-1)
//             break;
//         tail->next = createNode(tmp);
//         tail = tail->next;
//     }
    
//     int k;
//     scanf("%d", &k);
//     Node* res = Solver(head, k);
//     printList(res);
    
//     return 0;
// }
