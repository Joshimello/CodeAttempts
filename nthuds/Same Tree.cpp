#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <map>
using namespace std;

string build(auto& PR, auto& IN, auto& M, int& cur, int l, int r, auto& BT){
  if(l > r || cur >= PR.size()) return "#";
  string val = PR[cur++];

  string lv = build(PR, IN, M, cur, l, M[val]-1, BT);
  string rv = build(PR, IN, M, cur, M[val]+1, r, BT);
  BT[val] = {lv, rv};
  return val;
}

void printPost(auto& BT, string s, auto& PO2){
  auto [l, r] = BT[s];
  if(l != "#") printPost(BT, l, PO2);
  if(r != "#") printPost(BT, r, PO2);
  PO2.push_back(s);
}

void solve(){
  int n; cin >> n;
  vector<string> PR, IN, PO;
  map<string, int> M;
  for(int i = 0; i < n; i++){
    string t; cin >> t;
    PR.push_back(t);
  }
  for(int i = 0; i < n; i++){
    string t; cin >> t;
    IN.push_back(t);
    M[t] = i;
  }
  for(int i = 0; i < n; i++){
    string t; cin >> t;
    PO.push_back(t);
  }
  int cur = 0;
  map<string, tuple<string, string>> BT;
  build(PR, IN, M, cur, 0, n-1, BT);

  vector<string> PO2;
  printPost(BT, PR[0], PO2);

  bool isSame = true;
  for(int i = 0; i < n; i++){
    if(PO[i] != PO2[i]){
      isSame = false;
      break;
    }
  }
  if(isSame) cout << "yes" << endl;
  else cout << "no" << endl;
}

int main(){
  int t; cin >> t;
  while(t--){
    solve();
  }
}