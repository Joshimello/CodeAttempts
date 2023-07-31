#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <map>
using namespace std;
string sy(string s){
  map<char, int> prio = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
  stack<char> op;
  string p;
  for(char& i : s){
    if(i >= 'A' && i <= 'Z') p.push_back(i);
    else if(i == '+' || i == '-' || i == '*' || i == '/'){
      while(op.size() && prio[op.top()] >= prio[i] && op.top() != '('){
        p.push_back(op.top());
        op.pop();
      }
      op.push(i);
    }
    else if(i == '(') op.push(i);
    else if(i == ')'){
      while(op.top() != '('){
        p.push_back(op.top());
        op.pop();
      }
      op.pop();
    }
  }
  while(op.size()){
    p.push_back(op.top());
    op.pop();
  }
  return p;
}
int main(){
  string s; cin >> s;
  string p = sy(s);
  // cout << p << endl;
  int t; cin >> t;
  while(t--){
    vector<int> v(5);
    for(int& i : v){
      cin >> i;
    }
    stack<int> st;
    for(char& i : p){
      if(i >= 'A' && i <= 'Z') st.push(v[i-'A']);
      else{
        int a = st.top(); st.pop();
        int b = st.top(); st.pop();
        if(i == '+') st.push(b + a);
        else if(i == '-') st.push(b - a);
        else if(i == '*') st.push(b * a);
        else if(i == '/') st.push(b / a);
      }
    }
    cout << st.top() << endl;
  }
}