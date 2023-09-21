#include <iostream>
#include <string>
#include <set>

using namespace std;

void insert(multiset<int> *s, int x){
  s->insert(x);
}

void query(multiset<int> *s, int x, int k){
  multiset<int>::iterator i = s->upper_bound(--x);
  while(--k && i != s->end()){
    ++i;
  }
  if(i == s->end()){
    cout << -1 << endl;
    return;
  }
  cout << *i << endl;
}

void print(multiset<int> *s){
  multiset<int>::iterator i;
  for(i = s->begin(); i != s->end(); i++){
    cout << *i << " ";
  }
}

int main(){
  multiset<int> s;
  string cmd;
  while(cin >> cmd){
    if(cmd == "Insert"){
      int x; cin >> x;
      insert(&s, x);
    }
    else if(cmd == "Query"){
      int x, k; cin >> x >> k;
      query(&s, x, k);
    }
  }
  // print(&s);
}