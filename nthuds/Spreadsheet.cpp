#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> con;
vector<int> val;
vector<int> calc;
vector<int> state;

int dfs(int i){
  if(state[i] == -1) return -1;
  if(state[i] == 0){
    state[i] = -1;
    calc[i] = val[i];
    for(int& j : con[i]){
      int t = dfs(j);
      if(t == -1) return -1;
      calc[i] += t;
    }
    state[i] = 1;
  }
  return calc[i];
}

int main(){
  int n, m; cin >> n >> m;
  con.resize(n+1);  
  val.resize(n+1);  
  calc.resize(n+1, 0);  
  state.resize(n+1, 0);  
  while(m--){
    char c; cin >> c;
    int a; cin >> a;
    for(int i = 'A'; i < c; i++){
      int b; cin >> b;
      con[a].push_back(b);
    }
    cin >> val[a];
  }

  for(int i = 1; i <= n; i++){
    int t = dfs(i);
    if(t == -1) cout << "#REF!" << endl;
    else cout << t << endl;
  }
}