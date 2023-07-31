#include <iostream>
#include <vector>
#include <tuple>
#include <map>
using namespace std;

vector<vector<int>> adj;
map<tuple<int, int>, int> dpA;
map<tuple<int, int>, int> dpB;

int B(int, int);

int A(int i, int p){
  if(dpA[{i, p}] != 0) return dpB[{i, p}];
  int s = 0;
  for(int& j : adj[i]){
    if(j == p) continue;
    s += B(j, i);
  }
  return dpA[{i, p}] = 1+s;
}

int B(int i, int p){
  if(dpB[{i, p}] != 0) return dpB[{i, p}];
  int s = 0;
  for(int& j : adj[i]){
    if(j == p) continue;
    s += max(A(j, i), B(j, i));
  }
  return dpB[{i, p}] = s;
}

int main(){
  int n; cin >> n;
  adj.resize(n+1);
  for(int i = 0; i < n-1; i++){
    int a, b; cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  
  cout << max(A(1, 0), B(1, 0)) << endl;
}