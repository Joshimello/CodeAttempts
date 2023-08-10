#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main(){
  int n, m; cin >> n >> m;
  vector<vector<int>> adj(n+1);
  vector<int> con(n+1, 0);
  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    adj[a].push_back(b);
    con[b]++;
  }

  multiset<int> q;
  for(int i = 1; i <= n; i++){
    if(con[i] == 0) q.insert(i);
  }

  int v = 0;
  vector<int> ans;
  while(q.size()){
    int f = *q.begin();
    q.erase(q.begin());
    ans.push_back(f);
    for(int& i : adj[f]){
      con[i]--;
      if(con[i] == 0){
        q.insert(i);
      }
    }
    v++;
  }

  if(v != n){
    cout << -1 << endl;
    return 0;
  }

  for(int& i : ans){
    cout << i << ' ';
  }
  cout << endl;
}