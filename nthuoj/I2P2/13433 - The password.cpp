#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct _Node {
  int val;
  struct _Node *l;
  struct _Node *r;
} Node;

void inorder(Node *root){
  if(root->l){
    inorder(root->l);
  }
  cout << root->val << " ";
  if(root->r){
    inorder(root->r);
  }
  free(root);
}

int main(){

  int test; cin >> test;
  while(test--){

  int n; cin >> n;

  Node *root = (Node*)malloc(sizeof(Node));
  root->val = 0;
  root->l = NULL;
  root->r = NULL;

  Node *temp = root;
  for(int i = 1; i <= n; i++){
    char t; cin >> t;
    if(t == 'L'){
      temp->l = (Node*)malloc(sizeof(Node));
      temp = temp->l;
      temp->val = i;
      temp->l = NULL;
      temp->r = NULL;
    }
    else if(t == 'R'){
      temp->r = (Node*)malloc(sizeof(Node));
      temp = temp->r;
      temp->val = i;
      temp->l = NULL;
      temp->r = NULL;
    }
  }

  inorder(root);
  cout << endl;


  }
}