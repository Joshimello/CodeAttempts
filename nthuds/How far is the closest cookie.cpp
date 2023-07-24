#include <iostream>
#include <utility>
#include <vector>
#include <queue>
using namespace std;
int main(){
  int test; cin >> test;
  while(test--){

    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n+1);
    while(m--){
      int u, v; cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    
    int tako; cin >> tako;

    int s; cin >> s;
    vector<bool> cookie(n+1, false);
    for(int i = 0; i < s; i++){
      int p; cin >> p;
      cookie[p] = true;
    }

    bool isFound = false;
    vector<bool> v(n+1, false);
    queue<pair<int, int>> q;
    q.push({tako, 0});
    while(q.size()){
      auto [f, d] = q.front();
      q.pop();

      if(v[f]) continue;
      v[f] = true;

      if(cookie[f]){
        cout << d << endl;
        isFound = true;
        break;
      }

      for(int& i : adj[f]){
        q.push({i, d+1});
      }
    }

    if(!isFound) cout << "SAD" << endl;

  }
}