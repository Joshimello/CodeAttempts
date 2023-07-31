#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int n;
vector<tuple<int, int>> child;
vector<int> parent;
vector<int> a;

void dfs(int i){
  if(i == -1) return;
  a.push_back(i);
  auto [l, r] = child[i];
  dfs(l);
  dfs(r);
}

int main(){
  cin >> n;
  child.resize(n+1);
  parent.resize(n+1);
  for(int i = 1; i <= n; i++){
    int a, b; cin >> a >> b;
    child[i] = {a, b};
    if(a != -1) parent[a] = i;
    if(b != -1) parent[b] = i;
  }

  int root;
  for(int i = 1; i <= n; i++){
    if(!parent[i]) root = i;
  }

  dfs(root);
  cout << a.back() << endl;
}