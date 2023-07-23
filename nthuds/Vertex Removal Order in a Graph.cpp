#include <iostream>
#include <vector>
using namespace std;
int main(){
  int n, m; cin >> n >> m;
  vector<vector<int>> adj(n+1);
  vector<int> adjc(n+1, 0);
  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
    adjc[a]++;
    adjc[b]++;
  }
  for(int i = 0; i < n; i++){
    int M, Ms = -1;
    for(int i = 1; i < n+1; i++){
      if(adjc[i] >= Ms){
        Ms = adjc[i];
        M = i;
      }
    }
    adjc[M] = -1;
    for(int i = 0; i < adj[M].size(); i++){
      adjc[adj[M][i]]--;
    }
    cout << M << " ";
  }
}