#include <iostream>
#include <vector>
using namespace std;
int main(){
  int n, m, q; cin >> n >> m >> q;
  vector<vector<int>> adj(n+1);
  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  while(q--){
    char c; cin >> c;
    if(c == 'D'){
      int a; cin >> a;
      cout << adj[a].size() << endl;
    }
    else {
      int a, b; cin >> a >> b;
      bool f = false;
      for(int& i : adj[a]){
        if(i == b){
          f = true;
          break;
        }
      }
      cout << (f ? 'Y' : 'N') << endl;
    }
  }
}