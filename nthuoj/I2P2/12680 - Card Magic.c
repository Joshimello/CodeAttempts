#include<stdio.h>
#include<stdlib.h>

#ifndef __FUNCTION_H__
#define __FUNCTION_H__
typedef struct _Node{
  int size;
  int* data;
  struct _Node* next;
} Node;


Node* ReadOneList(){
  int len;
  scanf("%d: ", &len);
  
  Node * newNode = (Node*)malloc(sizeof(Node));

  newNode->size = len;

  int * newArray = (int*)malloc(sizeof(int) * len);

  for(int i = 0; i < len; i++){
    int n;
    scanf("%d", &n);
    newArray[i] = n;
  }

  newNode->data = newArray;

  newNode->next = NULL;

  return newNode;
}

void PrintList(Node* dummyHead){
  for(Node * temp = dummyHead->next; temp != NULL; temp = temp->next){
    //printf("[%d] ", temp->size);
    for(int i = 0; i < temp->size; i++){
      printf(i < temp->size - 1 ? "%d " : "%d", temp->data[i]);
    }
    printf("\n");
  }
}

void Merge(Node* dummyHead, int a, int b){
  Node * stackAPrev = dummyHead;
  while(--a){
    stackAPrev = stackAPrev->next;
  }
  Node * stackA = stackAPrev->next;
  Node * stackANext = stackA->next;

  Node* stackBPrev = dummyHead;
  while(--b){
    stackBPrev = stackBPrev->next;
  }
  Node * stackB = stackBPrev->next;
  Node * stackBNext = stackB->next;

  Node * newNode = (Node*)malloc(sizeof(Node));
  newNode->size = stackA->size + stackB->size;
  
  newNode->data = (int*)malloc(sizeof(int) * newNode->size);
  
  for(int i = 0; i < stackB->size; i++){
    newNode->data[i] = stackB->data[i];
  }
  
  for(int i = 0; i < stackA->size; i++){
    newNode->data[i + stackB->size] = stackA->data[i];
  }

  if(stackBNext == stackA){
    stackBPrev->next = newNode;
    newNode->next = stackANext;
  }

  else if(stackANext == stackB){
    stackAPrev->next = newNode;
    newNode->next = stackBNext;
  }

  else{
    stackBPrev->next = newNode;
    newNode->next = stackBNext;

    stackAPrev->next = stackANext;
  }

  free(stackB->data);
  free(stackB);

  free(stackA->data);
  free(stackA);
}

void Cut(Node* dummyHead, int stackNum, int amount){
  Node * stackPrev = dummyHead;
  while(--stackNum){
    stackPrev = stackPrev->next;
  }
  Node * stack = stackPrev->next;


  Node * firstNode = (Node*)malloc(sizeof(Node));
  firstNode->size = amount;
  firstNode->data = (int*)malloc(sizeof(int) * firstNode->size);
  for(int i = 0; i < firstNode->size; i++){
    firstNode->data[i] = stack->data[i];
  }

  Node * secondNode = (Node*)malloc(sizeof(Node));
  secondNode->size = stack->size - amount;
  secondNode->data = (int*)malloc(sizeof(int) * secondNode->size);
  for(int i = 0; i < secondNode->size; i++){
    secondNode->data[i] = stack->data[i + firstNode->size];
  }

  stackPrev->next = firstNode;
  firstNode->next = secondNode;
  secondNode->next = stack->next;

  free(stack->data);
  free(stack);
}


#endif
int main(){
  Node* dummy_head;
  Node* tail;

  dummy_head = (Node*) malloc( sizeof(Node) );
  dummy_head->data = NULL;
  dummy_head->size = -1;

  tail = dummy_head;

  int N, M;
  scanf("%d %d", &N, &M);
  for(int i=0; i<N; i++){
    tail->next = ReadOneList();
    tail = tail->next;   
  }
  char act[10];
  int x, y;
  for(int i=0; i<M; i++){
    scanf("%s %d %d", act, &x, &y);
    if( act[0] == 'M' ){
      Merge(dummy_head, x, y);
    }
    else{
      Cut(dummy_head, x, y);
    }
  }
  PrintList(dummy_head);
  return 0;
}
