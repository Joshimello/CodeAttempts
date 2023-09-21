#include <iostream>
#include <vector>
using namespace std;
int main(){
  int T; cin >> T;
  while(T--){

    int n, k; cin >> n >> k;
    vector<int> ps;
    int t; cin >> t;
    ps.push_back(t);
    for(int i = 1; i < n; i++){
      int t; cin >> t;
      ps.push_back(t + ps[i-1]);
    }
    
  }
}