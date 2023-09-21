#include <iostream>
#include <set>
using namespace std;
int main(){
  int n; cin >> n;
  set<int> s;
  while(n--){
    int t; cin >> t;
    s.insert(t);
    set<int>::iterator i = s.find(t);
    if(++i == s.end()) continue;
    s.erase(i);
  }
  cout << s.size() << endl;
  // set<int>::iterator i;
  // for(i = s.begin(); i != s.end(); i++){
  //   cout << *i << ' ';
  // }
}