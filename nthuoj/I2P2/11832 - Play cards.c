#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct _Node {
  int data;
  struct _Node * next;
} Node;
int main(){
  int cardLen, opLen;
  scanf("%d %d", &cardLen, &opLen);
  
  Node * head = malloc(sizeof(Node));
  Node * temp = head;
  for(int i = 0; i < cardLen; i++){
    int num;
    scanf("%d", &num);
    temp->data = num;
    if(i == cardLen-1)
      temp->next = NULL;
    else
      temp->next = malloc(sizeof(Node));
    temp = temp->next;
  }

  while(opLen--){
    char op[4];
    scanf("%s", op);
    if(!strcmp(op, "ADD")){
      int pos, val;
      scanf("%d %d", &pos, &val);
      if(pos == 0){
        Node * newNode = malloc(sizeof(Node));
        newNode->data = val;
        newNode->next = head;
        head = newNode;
      }
      else{
        temp = head;
        for(int i = 1; i < pos; i++){
          temp = temp->next;
        }
        Node * newNode = malloc(sizeof(Node));
        newNode->data = val;
        newNode->next = temp->next;
        temp->next = newNode;
      }

      //for(temp = head; temp != NULL; temp = temp->next){
      //  printf("%d\n", temp->data);
      //}
    }
    if(!strcmp(op, "CUT")){
      int start, end;
      scanf("%d %d", &start, &end);

      if(start == 0) continue;
      
      Node * beforeStartNode;
      Node * startNode;
      Node * endNode;
      Node * AfterEndNode;
      temp = head;
      
      for(int i = 1; i < start; i++)
        temp = temp->next;
      beforeStartNode = temp;
      startNode = temp->next;
      //printf("[%d]\n", startNode->data);
      
      for(int i = 0; i < end; i++)
        temp = temp->next;
      endNode = temp;
      AfterEndNode = temp->next;
      //printf("[%d]\n", endNode->data);
      
      beforeStartNode->next = AfterEndNode;
      endNode->next = head;
      head = startNode;
    }
  }
  
  for(temp = head; temp != NULL; temp = temp->next){
    printf("%d\n", temp->data);
  }
}