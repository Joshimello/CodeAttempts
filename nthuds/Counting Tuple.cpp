#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
vector<ll> lt;
vector<ll> gt;
void M(vector<ll>& L, vector<ll>& R, vector<ll>& A){
  auto i = L.begin();
  auto j = R.begin();
  auto a = A.begin();
  while(i != L.end() && j != R.end()){
    if(*i < *j){
      gt[*i] += distance(j, R.end());
      *a = *i;
      i++; a++;
    }
    else {
      lt[*j] += distance(L.begin(), i);
      *a = *j;
      j++; a++;
    }
  }

  while(i != L.end()){
    *a = *i;
    i++; a++;
  }

  while(j != R.end()){
    lt[*j] += distance(L.begin(), i);
    *a = *j;
    j++; a++;
  }
}
void MS(vector<ll>& A){
  if(A.size() <= 1) return;
  ll mid = A.size()/2;
  vector<ll> L(A.begin(), A.begin()+mid);
  vector<ll> R(A.begin()+mid, A.end());

  MS(L);
  MS(R);
  M(L, R, A);
}
int main(){
  ll n; cin >> n;
  lt.resize(n+1, 0);
  gt.resize(n+1, 0);
  vector<ll> A;
  for(ll i = 0; i < n; i++){
    ll t; cin >> t;
    A.push_back(t);
  }
  MS(A);

  /*
  for(ll& i : lt) cout << i << ' ';
  cout << endl;
  for(ll& i : gt) cout << i << ' ';
  cout << endl;
  */

  ll ans = 0;
  for(ll i = 0; i <= n; i++){
    ans += lt[i] * gt[i];
  }
  cout << ans << endl;
}