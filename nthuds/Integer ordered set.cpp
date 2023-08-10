#include <iostream>
#include <set>
using namespace std;
int main(){
  set<int> s;
  int q; cin >> q;
  while(q--){
    char c; cin >> c;
    int a; cin >> a;
    if(c == 'I'){
      s.insert(a);
      cout << s.size() << endl;
    }
    else if(c == 'D'){
      s.erase(a);
      cout << s.size() << endl;
    } 
    else if(c == 'S'){
      if(s.find(a) != s.end()) cout << "YES" << endl;
      else cout << "NO" << endl;
    }
    else if(c == 'L'){
      auto i = s.lower_bound(a);
      if(i != s.end()) cout << *i << endl;
      else cout << -1 << endl;
    }
    else if(c == 'U'){
      auto i = s.upper_bound(a);
      if(i != s.end()) cout << *i << endl;
      else cout << -1 << endl;
    }
  }
}