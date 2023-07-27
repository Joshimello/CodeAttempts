#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <set>
using namespace std;
using ll = long long;
int main(){
  int n; cin >> n;
  vector<vector<tuple<int, ll>>> adj(n+1);
  for(int i = 0; i < n-1; i++){
    ll u, v, b; cin >> u >> v >> b;
    adj[u].push_back({v, b});
    adj[v].push_back({u, b});
  }

  set<tuple<int, ll>> lowly;

  vector<bool> v(n+1, false);
  queue<tuple<int, ll>> q;
  q.push({1, 0});
  while(q.size()){
    auto [f, b] = q.front();
    q.pop();

    if(v[f]) continue;
    v[f] = true;

    if(adj[f].size() <= 1){
      lowly.insert({f, b});
    }

    for(auto& [i, bi] : adj[f]){
      q.push({i, b+bi});
    }
  }

  for(auto& [i, b] : lowly){
    cout << "City " << i << ": " << b << endl;
  }
}