#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
  int q; cin >> q;
  vector<int> A;
  while(q--){
    char c; cin >> c;
    if(c == '+'){
      int t; cin >> t;
      A.push_back(t);
    }
    else if(c == '-'){
      int t; cin >> t;
      A.push_back(-t);
    }
    else if(c == 'U'){
      string t; cin >> t;
      if(!A.size()) continue;
      A.pop_back();
    }
  }
  int s = 0;
  for(int& i : A){
    s += i;
  }
  cout << s << endl;
}