#include<iostream>
#include<string.h>



#ifndef FUNCTION_H
#define FUNCTION_H
#include <iostream>

using namespace std;

class ListNode
{
    friend class List_stack; //make List_stack a friend
    public:
        ListNode( const int &info ) //constructor
        : data( info ), nextPtr( NULL ), prevPtr( NULL )
        {
        } //end ListNode constructor

    private:
        int data; //data
        ListNode *nextPtr; // next node in list
        ListNode *prevPtr;
}; //end class ListNode

class List_stack {
    public:
        List_stack();
        ~List_stack();
        void push(const int &num);
        void pop();
        void print();
    private:
        ListNode *head;
        ListNode *tail;
};

List_stack::List_stack(){
    head = new ListNode(0);
    tail = head;
}
List_stack::~List_stack(){
    for(ListNode *temp = head->nextPtr; temp != NULL; temp = temp->nextPtr){
        delete temp->prevPtr;
    }
}
void List_stack::push(const int &num){
    ListNode *newNode = new ListNode(num);
    tail->nextPtr = newNode;
    newNode->prevPtr = tail;
    newNode->nextPtr = NULL;
    tail = newNode;
}
void List_stack::pop(){
    ListNode *before = tail->prevPtr;
    before->nextPtr = NULL;
    delete tail;
    tail = before;
}

void List_stack::print(){
    for(ListNode *temp = head->nextPtr; temp != NULL; temp = temp->nextPtr){
        cout << temp->data << " ";
    }
}
#endif // FUNCTION_H




int main(){
    List_stack L_stack;
    char command[10];
    int n;
    while(cin>>command){

        if(strcmp(command,"pop")==0){
            L_stack.pop();
        }else if(strcmp(command,"push")==0){
            cin >> n;
            L_stack.push(n);
        }else if(strcmp(command, "print") == 0){
            L_stack.print();
            cout << endl;
        }
    }
    return 0;
}
