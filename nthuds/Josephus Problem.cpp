#include <iostream>
using namespace std;
struct node{
  int v;
  node* next;
};
int main(){
  int n; cin >> n;
  node* head = new node;
  node* it = head;
  for(int i = 1; i < n; i++){
    it->v = i;
    it->next = new node;
    it = it->next;
  }
  it->v = n;
  it->next = head;
  it = it->next;

  for(int i = 0; i < n; i++){
    cout << it->next->v << ' ';
    it->next = it->next->next;
    it = it->next;
  }
}