#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#ifndef FUNCTION_H
#define FUNCTION_H

#define MAXEXPR 256
#define NUMSYM 6

char expr[MAXEXPR];  // string to store the input expression.
int pos;             // current position of parsing, from end to start

typedef enum {ID_A, ID_B, ID_C, ID_D, OP_AND, OP_OR} TokenSet;
char sym[NUMSYM];

typedef struct _Node {
    TokenSet data;
    struct _Node *left, *right;
} BTNode;

BTNode* makeNode(char c) {
    BTNode *node = (BTNode*)malloc(sizeof(BTNode));
    if(c == 'A') node->data = ID_A;
    else if(c == 'B') node->data = ID_B;
    else if(c == 'C') node->data = ID_C;
    else if(c == 'D') node->data = ID_D;
    else if(c == '&') node->data = OP_AND;
    else if(c == '|') node->data = OP_OR;
    node->left = NULL;
    node->right = NULL;
    return node;
}

BTNode* EXPR();
BTNode* FACTOR() {
    if (expr[pos] >= 'A' && expr[pos] <= 'D') {
        return makeNode(expr[pos--]);
    }
    else if (expr[pos] == ')') {
        pos--;
        BTNode *node = EXPR();
        pos--;  // skip the '('
        return node;
    }
}

BTNode* EXPR() {
    BTNode *right = FACTOR();
    if (pos >= 0 && (expr[pos] == '&' || expr[pos] == '|')) {
        BTNode *root = makeNode(expr[pos--]);
        root->right = right;
        root->left = EXPR();
        return root;
    }
    return right;
}

void freeTree(BTNode *root);
void printPrefix(BTNode *root);

#endif


int main(void){
    sym[0]='A';
    sym[1]='B';
    sym[2]='C';
    sym[3]='D';
    sym[4]='&';
    sym[5]='|';
    while (scanf("%s", expr)!=EOF)
    {
        pos = strlen(expr) - 1;
        BTNode *root = EXPR();
        printPrefix(root);
        printf("\n");
        freeTree(root);
    }

    return 0;
}

/* print a tree by pre-order. */
void printPrefix(BTNode *root){
    if (root != NULL) {
        printf("%c",sym[root->data]);
        printPrefix(root->left);
        printPrefix(root->right);
    }
}

/* clean a tree.*/
void freeTree(BTNode *root){
    if (root!=NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

