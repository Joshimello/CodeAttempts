#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){
  int n, m; cin >> n >> m;
  vector<vector<int>> adj(n+1), rev(n+1);
  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    adj[a].push_back(b);
    rev[b].push_back(a);
  }

  vector<bool> v(n+1, false);
  queue<int> q;
  q.push(1);
  while(q.size()){
    int f = q.front();
    q.pop();

    if(v[f]) continue;
    v[f] = true;

    for(int& i : adj[f]){
      q.push(i);
    }
  }

  vector<bool> rv(n+1, false);
  queue<int> rq;
  rq.push(1);
  while(rq.size()){
    int f = rq.front();
    rq.pop();

    if(rv[f]) continue;
    rv[f] = true;

    for(int& i : rev[f]){
      rq.push(i);
    }
  }

  for(int i = 1; i <= n; i++){
    if(!v[i] || !rv[i]){
      cout << "NO" << endl;
      return 0;
    }
  }

  cout << "YES" << endl;
}