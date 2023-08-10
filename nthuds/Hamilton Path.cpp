#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
int main(){
  int n, m; cin >> n >> m;
  vector<vector<int>> dag(n+1);
  vector<int> con(n+1, 0);
  while(m--){
    int a, b; cin >> a >> b;
    dag[a].push_back(b);
    con[b]++;
  }

  vector<int> topo;
  queue<int> q;
  for(int i = 1; i <= n; i++){
    if(con[i] == 0) q.push(i);
  }
  while(q.size()){
    auto f = q.front();
    q.pop();
    topo.push_back(f);
    for(int& i : dag[f]){
      con[i]--;
      if(con[i] == 0){
        q.push(i);
      }
    }
  }

  vector<int> dp(n+1);
  for(int& i : topo){
    for(int& j : dag[i]){
      dp[j] = max(dp[j], dp[i] + 1);
    }
  }

  int maxl = -1;
  for(int i = 1; i <= n; i++){
    maxl = max(maxl, dp[i]);
  }

  if(maxl+1 == n) cout << "Yes" << endl;
  else cout << "No" << endl;
}