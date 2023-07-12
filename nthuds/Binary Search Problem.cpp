#include <iostream>
#include <map>
using namespace std;
int main(){
  int n, q; cin >> n >> q;
  map<long long, bool> m;
  for(int i = 0; i < n; i++){
    long long a; cin >> a;
    m[a] = true;
  }
  for(int i = 0; i < q; i++){
    long long b; cin >> b;
    if(m[b]) cout << "Y ";
    else cout << "N ";
  }
  cout << endl;
}