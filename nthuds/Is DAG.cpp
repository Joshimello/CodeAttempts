#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){
  int n, m; cin >> n >> m;
  vector<vector<int>> dir(n+1);
  vector<int> con(n+1, 0);
  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    dir[a].push_back(b);
    con[b]++;
  }
  
  queue<int> q;
  for(int i = 1; i <= n; i++){
    if(con[i] == 0) q.push(i);
  }
  vector<int> ans;
  while(q.size()){
    int f = q.front();
    ans.push_back(f);
    q.pop();
    for(int& i : dir[f]){
      con[i]--;
      if(con[i] == 0){
        q.push(i);
      }
    }
  }
  if(ans.size() != n) cout << "NO" << endl;
  else cout << "YES" << endl;
}