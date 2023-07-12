#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
ll MS(vector<ll>& A){
  if(A.size() <= 1) return 0;
  ll mid = A.size()/2;
  vector<ll> L(A.begin(), A.begin()+mid);
  vector<ll> R(A.begin()+mid, A.end());

  ll inv = 0;

  inv += MS(L) + MS(R);
  merge(L.begin(), L.end(), R.begin(), R.end(), A.begin());

  auto it = R.begin();
  for(ll& i : L){
    while(it != R.end() && *it < i) it++;
    inv += distance(R.begin(), it);
  }

  return inv;
}
int main(){
  ll n; cin >> n;
  vector<ll> A;
  for(ll i = 0; i < n; i++){
    ll t; cin >> t;
    A.push_back(t);
  }
  cout << MS(A) << endl;
}