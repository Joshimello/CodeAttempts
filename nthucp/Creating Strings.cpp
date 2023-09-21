#include <iostream>
#include <queue>
#include <set>
using namespace std;
set<string> S;
void perm(string& a, int l, int r){
  if(l == r){
    // cout << a << endl;
    S.insert(a);
    return;
  }
  for(int i = l; i <= r; i++){
    swap(a[l], a[i]);
    perm(a, l+1, r);
    swap(a[l], a[i]);
  }
}
int main(){
  string s; cin >> s;
  // sort(s.begin(), s.end());
  perm(s, 0, s.size()-1);

  cout << S.size() << endl;
  for(string i : S){
    cout << i << endl;
  }
}