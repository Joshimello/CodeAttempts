#include <iostream>
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

    vector<bool> vst(n+1, false);

    int ans = 0;
    queue<int> q;
    for(int i = 1; i <= n; i++){
      if(vst[i]) continue;
      ans++;

      q.push(i);
      while(q.size()){
        int f = q.front();
        vst[f] = true;
        q.pop();
        for(int& j : adj[f]){
          if(vst[j]) continue;
          q.push(j);
        }
      }

    }

    cout << ans << endl;
  }
}