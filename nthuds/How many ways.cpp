#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){
  int n, m; cin >> n >> m;
  vector<vector<int>> dag(n+1);
  vector<int> con(n+1, 0);
  for(int i = 0; i < m; i++){
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
    int f = q.front();
    q.pop();
    topo.push_back(f);
    for(int& i : dag[f]){
      con[i]--;
      if(con[i] <= 0){
        q.push(i);
      }
    }
  }

  vector<long long> dp(n+1, 0);
  dp[1] = 1;

  for(int& i : topo){
    for(int& j : dag[i]){
      dp[j] = (dp[i] + dp[j]) % 1000000007;
    }
  }

  cout << dp[n] << endl;

}