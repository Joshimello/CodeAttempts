#include <stdio.h>
#include <stdlib.h>

#include <stdbool.h>

typedef struct _node{
    int val;
    struct _node *next;
    struct _node *prev;
} node;

// return true value if the linked list is a palindrome, otherwise false

bool is_palindrome(node *head){
    node * prevNode = NULL;
    for(node * temp = head; temp != NULL; temp = temp->next){
        temp->prev = prevNode;
        prevNode = temp;
    }

    // prevNode is now the last node
    while(head != NULL){
        if(head->val != prevNode->val) return false;
        head = head->next;
        prevNode = prevNode->prev;
    }

    return true;
}

/* lazy method
bool is_palindrome(node *head){
    int n[100000], i = 0;
    for(node * temp = head; temp != NULL; temp = temp->next){
        n[i++] = temp->val;
    }

    int left = 0, right = i - 1;
    while(left < right){
        if(n[left++] != n[right--]) return false;
    }

    return true;
}
*/


// main
#ifdef putchar_unlocked
#define putchar putchar_unlocked
#endif

int main()
{
    int n;
    while (~scanf("%d", &n))
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
        putchar(is_palindrome(head) ? 'T' : 'F');
        while (head)
        {
            node *tmp = head;
            head = head->next;
            free(tmp);
        }
    }
    putchar('\n');
    return 0;
}
