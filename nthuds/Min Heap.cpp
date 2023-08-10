#include <iostream>
#include <queue>
using namespace std;
int main(){
  int q; cin >> q;
  priority_queue<int, vector<int>, greater<int>> s;
  while(q--){
    int cmd; cin >> cmd;
    if(cmd == 1){
      int a; cin >> a;
      s.push(a);
    }
    else if(cmd == 2){
      if(s.size()) s.pop();
    }
    else if(cmd == 3){
      if(s.size()) cout << s.top() << endl;
      else cout << "EMPTY" << endl;
    }
  }
}