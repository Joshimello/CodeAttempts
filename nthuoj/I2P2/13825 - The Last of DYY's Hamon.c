#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    int id;
    struct _Node* next;
} Node;

void reverse(Node *node_l, Node *node_r){
    
    Node * end = node_r->next;
    printf("[%d]", end->id);

    Node * temp = node_l;
    while(temp != end){
        temp = temp->next;
        temp->next = end;
        end = temp;
    }

    node_l->next = end;
}

int main() {
    int n, q;
    Node *cc[101];
    scanf("%d%d", &n, &q);
    Node *head = (Node*)malloc(sizeof(Node));
    Node *node = head;
    cc[1] = node;
    scanf("%d", &head->id);
    for (int i=2; i<=n; i++) {
        node->next = (Node*)malloc(sizeof(Node));
        node = node->next;
        cc[i] = node;
        scanf("%d", &node->id);
    }
    while (q--) {
        int l, r;
        scanf("%d%d", &l, &r);
        Node *node_l, *node_r;
        node = head;
        for (int i=1; i<=r; i++) {
            if (i == l-1) node_l = node;
            if (i == r) node_r = node;
            node = node->next;
        }
        for (int i=l, j=r; i<j; i++, j--) {
            Node *tmp = cc[i];
            cc[i] = cc[j];
            cc[j] = tmp;
        }
        reverse(node_l, node_r);
    }
    node = head;
    for (int i=1; i<=n; i++) {
        if (cc[i] != node) {
            printf("Fail...\n");
            return 0;
        }
        printf("%d ", node->id);
        node = node->next;
    }
    printf("\npikachuuuu!!\n");
    return 0;
}
