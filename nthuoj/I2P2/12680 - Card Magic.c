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
  scanf("%d", &len);
  
}

void PrintList(Node*){

}

void Merge(Node*, int, int){

}

void Cut(Node*, int, int){

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
