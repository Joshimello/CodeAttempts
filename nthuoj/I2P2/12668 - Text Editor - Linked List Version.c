#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
	char val;
	struct _Node * next;
	struct _Node * prev;
} Node;

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		Node * head = (Node*)malloc(sizeof(Node));
		Node * rear = (Node*)malloc(sizeof(Node));
		head->next = rear;
		head->val = NULL;
		rear->prev = head;
		rear->val = NULL;

		Node * cur = head;

		int len;
		scanf("%d", &len);

		while(len--){
			char c;
			scanf(" %c", &c);

			if(c == 'L'){
				cur = cur->prev;
			}

			else if(c == 'R'){
				cur = cur->next;
			}

			else if(c == 'B'){
				Node * beforeCur = cur->prev;
				Node * afterCur = cur->next;

				beforeCur->next = afterCur;
				afterCur->prev = beforeCur;

				free(cur);
				cur = beforeCur;
			}

			else {
				Node * afterCur = cur->next;

				Node * newNode = (Node*)malloc(sizeof(Node));
				newNode->val = c;
				newNode->prev = cur;
				newNode->next = afterCur;

				cur->next = newNode;
				afterCur->prev = newNode;

				cur = newNode;
			}
		}

		for(Node * temp = head->next; temp->val != NULL; temp = temp->next){
			printf("%c", temp->val);
		}

		printf("\n");
	}
}