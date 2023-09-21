#include <iostream>
#include <vector>
using namespace std;
int main(){
  int n, l; cin >> n >> l;
  vector<pair<int, char>> a;
  for(int i = 0; i < n; i++){
    int p; char d; cin >> p >> d;
    a.push_back({p, d});
  }
  int q; cin >> q;
  while(q--){
    int t; cin >> t;
    auto aa = a;
    int am = aa.size();
    for(auto [p, d] : aa){
      if(d == 'L') p -= t;
      else p += t;
      if(p >= l || p <= 1) am--;
    }
    cout << am << endl;
  }
}