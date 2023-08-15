#include <iostream>
#include <set>
using namespace std;
int main(){
  int n, q; cin >> n >> q;
  set<pair<int, int>> S;
  while(q--){
    int c, a, b; cin >> c >> a >> b;
    if(c == 1){
      S.insert({max(a, b), min(a, b)});
    }
    else{
      if(S.find({max(a, b), min(a, b)}) != S.end())
        cout << "yes" << endl;
      else cout << "no" << endl;
    }
  }
}