#include <iostream>
#include <string>
#include <deque>
using namespace std;
int main(){
  int n; cin >> n;
  deque<int> a;
  while(n--){
    string op; cin >> op;
    if(op == "IH"){
      int t; cin >> t;
      a.push_front(t);
    }
    else if(op == "IT"){
      int t; cin >> t;
      a.push_back(t);
    }
    else if(op == "RH"){
      if(a.empty()) continue;
      a.pop_front();
    }
    else if(op == "RT"){
      if(a.empty()) continue;
      a.pop_back();
    }
    else if(op == "O"){
      if(a.empty()){
        cout << 'E' << endl;
        continue;
      }
      for(int i : a){
        cout << i << ' ';
      }
      cout << endl;
    }
    else if(op == "S"){
      int t; cin >> t;
      if(a.empty()){
        cout << 'E' << endl;
        continue;
      }
      bool found = false;
      for(int i : a){
        if(t == i){
          found = true;
        }
      }
      cout << (found ? "Y" : "N") << endl;
    }
  }
}