#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main(){
  string s; cin >> s;
  vector<int> Z(s.size(), 0);
  for(int i = 1, j = 0; i < s.size(); i++){
    while(j > 0 && s[i] != s[j]) j = Z[j-1];
    if(s[i] == s[j]) j++;
    Z[i] = j;
  }
  stack<int> S;
  for(int i = Z[Z.size()-1]; i > 0;){
    S.push(i);
    i = Z[i-1];
  }
  while(S.size()){
    cout << S.top() << ' ';
    S.pop();
  }
}