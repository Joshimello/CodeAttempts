#include <stdio.h>
#include <stdlib.h>

#ifndef FUNCTION_H
#define FUNCTION_H

typedef struct treeNode {
    char data;
    struct treeNode *left;
    struct treeNode *right;
} Node;

void constructTree(Node** head);
void printInfix(Node *root);
void freeTree(Node *root);

void printInfixx(Node *root, int lvl)
{
    if (root == NULL)
        return;

    if ((root->data == '&' || root->data == '|') && lvl)
        printf("(");

    printInfixx(root->left, 0);
    printf("%c", root->data);
    printInfixx(root->right, 1);

    if ((root->data == '&' || root->data == '|') && lvl)
        printf(")");
}

void printInfix(Node *root){
    printInfixx(root, 0);
}

#endif

void constructTree(Node** head)
{
    char c;

    if((*head)==NULL)
    {
        (*head) = (Node *)malloc(sizeof(Node));
    c = getchar();

    (*head)->data = c;

        (*head)->left = (*head)->right = NULL;

        if((*head)->left == NULL && ((*head)->data=='&' || (*head)->data=='|'))
            constructTree( &(*head)->left);
        if((*head)->right == NULL && ((*head)->data=='&' || (*head)->data=='|'))
            constructTree( &(*head)->right);
    }
}

void freeTree(Node *root)
{
    if (root!=NULL)
    {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main(void)
{
    int n;
    scanf("%d", &n);// the number of test cases

    while(n>0)
    {
        getchar();
        Node *root=NULL;
        constructTree(&root);// construct syntax tree
        printInfix(root);// you have to implement this function
        printf("\n");
        freeTree(root);
        --n;
    }

    return 0;
}
