#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std; 
struct DSU {
  vector<int> dsu, sz;
  DSU(int n) {
    dsu.resize(n + 1);
    sz.resize(n + 1, 1);
    for (int i = 0; i <= n; i++) dsu[i] = i;
  }
  int get(int x) {
    return (dsu[x] == x ? x : dsu[x] = get(dsu[x]));
  }
  void oni(int a, int b) {
    a = get(a), b = get(b);
    if(a == b) return; 
    if(sz[a] > sz[b]) swap(a, b);
    dsu[a] = b;
    sz[b] += sz[a];
  }
};

int main() {
  int n, m; cin >> n >> m;
  DSU dsu(n);
 
  vector<tuple<int, int, int>> edge;
  for (int i = 0; i < m; i++) {
    int u, v, w; 
    cin >> u >> v >> w;
    edge.push_back(make_tuple(w, u, v));
  }

  sort(edge.begin(), edge.end());

  long long ans = 0;
  for (auto [w, u, v] : edge) {
    if (dsu.get(u) == dsu.get(v))
      continue;
    ans += w;
    dsu.oni(u, v);
  }
  cout << ans;
}