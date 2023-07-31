#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> counts;
vector<vector<int>> adj;
void subsize(int s, int e){
  counts[s] = 1;
  for(int& i : adj[s]){
    if(i == e) continue;
    subsize(i, s);
    counts[s] += counts[i];
  }
}
int main(){
  int n; cin >> n;
  counts.resize(n+1);
  adj.resize(n+1);
  for(int i = 2; i <= n; i++){
    int t; cin >> t;
    adj[i].push_back(t);
    adj[t].push_back(i);
  }
  subsize(1, 0);
  for(int i = 1; i <= n; i++){
    cout << counts[i]-1 << ' ';
  }
  cout << endl;
}