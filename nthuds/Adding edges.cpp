#include <iostream>
#include <vector>
#include <set>
using namespace std;
struct DSU {
  int con, big = -1;
  vector<int> dsu, sz;
  DSU(int n) {
    dsu.resize(n + 1);
    sz.resize(n + 1, 1);
    con = n;
    for (int i = 0; i <= n; i++) dsu[i] = i;
  }
  int get(int x) {
    return (dsu[x] == x ? x : dsu[x] = get(dsu[x]));
  }
  int get_size(int x) {
    return sz[get(x)];
  }
  void oni(int a, int b) {
    a = get(a), b = get(b);
    if(a == b) return; 
    if(sz[a] > sz[b]) swap(a, b);
    dsu[a] = b;
    sz[b] += sz[a];
    if(sz[b] > big) big = sz[b];
    con--;
  }
};
int main(){
  int n, m; cin >> n >> m;
  DSU g(n);
  while(m--){
    int a, b; cin >> a >> b;
    g.oni(a, b);
    cout << g.con << ' ' << g.big << endl;
  }
}