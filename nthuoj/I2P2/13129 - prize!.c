#include <stdio.h>
#include <stdlib.h>

#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED

typedef struct _Node{
    int number;
    struct _Node* next;
    struct _Node* prev;
}Node;

Node* head;
Node* createList(int n){
    Node * newHead = (Node*)malloc(sizeof(Node));
    Node * newNode = newHead;
    Node * preNode = newHead;
    for(int i = 1; i <= n; i++){
        newNode->number = i;

        if(i < n){
            newNode->next = (Node*)malloc(sizeof(Node));
            newNode = newNode->next;
            newNode->prev = preNode;
            preNode = preNode->next;
        }
        else {
            newNode->next = newHead;
            newNode = newNode->next;
            newNode->prev = preNode;
        }
    }
    return newHead;
}

void solveJosephus(int n, int k){
    Node * curNode = head;
    Node * prevNode = head;
    Node * nextNode = head;
    
    while(k--){
        int m;
        scanf("%d", &m);

        int isClock = m % 2;

        m %= n;
        if(!m) m = n;

        if(isClock){
            curNode = nextNode;
            while(--m) curNode = curNode->next;
        }

        if(!isClock){
            curNode = prevNode;
            while(--m) curNode = curNode->prev;
        }

        printf("%d\n", curNode->number);
        prevNode = curNode->prev;
        nextNode = curNode->next;
        free(curNode);
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        
        n--;
    }
}


#endif
// main
int main(){

    int n, k;

    while(scanf("%d%d", &n, &k)!=EOF){
        head = createList(n);
        solveJosephus(n, k);
    }

    return 0;
}