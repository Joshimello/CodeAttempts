#include <iostream>
#include <vector>
using namespace std;
int main(){
  int test; cin >> test;
  while(test--){
    int n, m; cin >> n >> m;
    vector<int> V;
    for(int i = 0; i <= n; i++){
      V.push_back(i);
    }
    while(m--){
      int a, b; cin >> a >> b;
      int x = max(a, b), y = min(a, b);
      V[x] = V[y];
    }
    for(int& i : V){
      cout << i << ' ';
    }
    cout << endl;
  }
}