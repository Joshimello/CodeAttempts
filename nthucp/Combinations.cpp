#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> v;
vector<int> c;

void pick(int d, int l){
  if(d == 0){
    for(int i : c) cout << i << ' ';
    cout << endl;
    return;
  }
  for(int i = l; i < n; i++){
    c.push_back(v[i]);
    pick(d-1, i+1);
    c.pop_back();
  }
}

int main(){
  int k; cin >> n >> k;
  for(int i = 0; i < n; i++){
    int t; cin >> t;
    v.push_back(t);
  }
  pick(k, 0);
}