#include <iostream>
#include <map>
using namespace std;
int main(){
  map<int, int> s;
  int q; cin >> q;
  while(q--){
    char c; cin >> c;
    int a; cin >> a;
    if(c == 'I'){
      s[a]++;
      cout << s.size() << endl;
    }
    else if(c == 'D'){
      s[a]--;
      if(s[a] <= 0) s.erase(a);
      cout << s.size() << endl;
    } 
    else if(c == 'C'){
      cout << s[a] << endl;
      if(s[a] <= 0) s.erase(a);
    }
    else if(c == 'L'){
      auto i = s.lower_bound(a);
      if(i != s.end()) cout << (*i).first << endl;
      else cout << -1 << endl;
    }
    else if(c == 'U'){
      auto i = s.upper_bound(a);
      if(i != s.end()) cout << (*i).first << endl;
      else cout << -1 << endl;
    }
  }
}