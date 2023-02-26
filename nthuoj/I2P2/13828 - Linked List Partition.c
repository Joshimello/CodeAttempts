#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int val;
    struct _node *next;
} node;

node *partition_linked_list(node * head, int pivot){

    node * leftHead = (node*)malloc(sizeof(node));
    node * rightHead = (node*)malloc(sizeof(node));

    node * leftRun = leftHead;
    node * rightRun = rightHead;

    leftRun->next = NULL;
    rightRun->next = NULL;

    for(node * temp = head; temp != NULL; temp = temp->next){
        if(temp->val < pivot){
            leftRun->next = temp;
            leftRun = leftRun->next;
        }
        else{
            rightRun->next = temp;
            rightRun = rightRun->next;
        }
    }

    leftRun->next = rightHead->next;
    rightRun->next = NULL;

    return leftHead->next;
}

// main
int main()
{
    int n, pivot;
    while (~scanf("%d%d", &n, &pivot))
    {
        node *head = (node*)malloc(sizeof(node)), *cur = head;
        while (n--)
        {
            scanf("%d", &(cur->val));
            if (n)
                cur = cur->next = (node*)malloc(sizeof(node));
            else
                cur->next = NULL;
        }
        head = partition_linked_list(head, pivot);
        for (cur = head; cur; cur = cur->next)
            printf("%d%c", cur->val, " \n"[!cur->next]);
        while (head)
        {
            node *tmp = head;
            head = head->next;
            free(tmp);
        }
    }
    return 0;
}