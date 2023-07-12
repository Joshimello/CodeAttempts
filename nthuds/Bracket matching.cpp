#include <iostream>
#include <stack>
using namespace std;
int main(){
  int T; cin >> T;
  while(T--){
    string s; cin >> s;
    stack<char> a;
    for(char& c : s){
      if(a.empty()){
        a.push(c);
      }
      else if(a.top() == '(' && c == ')' || a.top() == '[' && c == ']'){
        a.pop();
      }
      else{
        a.push(c);
      }
    }
    if(a.empty()){
      cout << 'Y' << endl;
      continue;
    }
    cout << 'N' << endl;
  }
}