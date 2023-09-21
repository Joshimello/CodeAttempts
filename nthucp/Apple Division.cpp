#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
int main(){
  int n; cin >> n;
  vector<int> v;
  long long s = 0;
  for(int i = 0; i < n; i++){
    int t; cin >> t;
    v.push_back(t);
    s += t;
  }

  long long m = 1e9;

  for(int i = 0; i < (1 << n); i++){
    long long ss = 0;
    for(int j = 0; j < n; j++){
      if((i & (1 << j)) != 0){
        ss += v[j];
        // cout << v[j] << ' ';
        // cout << '[' << j << ']' << ' ';
      }
    }
    if(ss == s) continue;

    long long d = abs(ss - (s-ss));
    m = min(m, d);

    // cout << s << ' ' << ss << ' ' << s-ss << endl;
    // cout << endl;
  }

  cout << m << endl;
}