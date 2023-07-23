#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
int main(){

  ll p = 31, m = 1e9+7;
  vector<ll> PW;
  PW.push_back(1);
  for(int i = 0; i < 6000; i++){
    PW.push_back(PW[i] * p);
  }

  int n, q; cin >> n >> q;
  vector<ll> H(n, 0);
  vector<ll> L(n, 0);
  for(int i = 0; i < n; i++){
    string s; cin >> s;
    L[i] = s.size();
    for(int j = 0; j < L[i]; j++){
      H[i] = (H[i] + s[j] * PW[j] % m) % m;
    }
    // cout << H[i] << endl;
  }

  while(q--){
    char c; cin >> c;
    int a, b; cin >> a >> b;
    if(c == 'E'){
      cout << (H[a-1] == H[b-1] ? 'Y' : 'N') << endl;
    }
    else {
      H[a-1] = (H[a-1] + H[b-1] * PW[L[a-1]] % m) % m;
      L[a-1] += L[b-1];
    }
  }

}