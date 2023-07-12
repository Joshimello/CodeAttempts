#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main(){
  ll n, m; cin >> n >> m;
  vector<ll> v;
  ll L = 0, R = 0;
  for(ll i = 0; i < n; i++){
    ll t; cin >> t;
    v.push_back(t);
    R = max(R, t);
  }
  if(m == n){
    cout << R << endl;
    return 0;
  }
  while(L < R){
    ll M = (L + R) / 2;

    ll count = 0;
    for(ll& i : v){
      if(i > M) count++;
    }

    if(count <= m-n) R = M;
    else L = M + 1;
  }
  cout << R << endl;
}