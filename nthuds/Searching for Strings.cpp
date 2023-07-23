#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;
using ll = long long;
int main(){
  string Ned, Hay; cin >> Ned >> Hay;
  vector<ll> cnt(30, 0);
  for(char& c : Ned){
    cnt[c-'a']++;
  }

  ll PW[300000]; 
  PW[0] = 1;
  ll p = 31, m = 1e9+7;
  for(ll i = 1; i <= Hay.size()+1; i++){
    PW[i] = PW[i-1] * p % m;
  }

  ll H[300000];
  H[0] = 0;
  for(ll i = 1; i <= Hay.size()+1; i++){
    H[i] = (H[i-1] + (Hay[i-1] * PW[i-1]) % m) % m;
  }

  set<ll> S;
  for(ll l = -Ned.size(), r = 0; r < Hay.size(); l++, r++){
    cnt[Hay[r]-'a']--;
    if(l >= 0) cnt[Hay[l]-'a']++;

    bool isZero = true;
    for(ll i = 0; i < 26; i++){
      // cout << cnt[i] << ' ';
      if(cnt[i]){
        isZero = false;
        break;
      }
    }
    // cout << endl;

    if(isZero){
      // cout << H[l+1] << ' ' << H[r+1] << ' ' << PW[Hay.size()-l] << endl;
      ll t = (((H[r+1] - H[l+1]) % m * PW[Hay.size()-l]) % m + m) % m;
      S.insert(t);
      // cout << t << endl;
    }

  }

  cout << S.size() << endl;

}