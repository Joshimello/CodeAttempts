#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

vector<tuple<int, int>> BT;
vector<int> PRE, IN, M;

int cur = 0;
int makePost(int l, int r){
  if(l > r) return -1;
  int val = PRE[cur++];
  BT[val] = {makePost(l, M[val]-1), makePost(M[val]+1, r)};
  return val;
}

void printPost(int n){
  auto [l, r] = BT[n];
  if(l != -1) printPost(l);
  if(r != -1) printPost(r);
  cout << n << ' ';
}

int main(){
  int n; cin >> n;
  BT.resize(n+1);
  M.resize(n+1);
  for(int i = 0; i < n; i++){
    int t; cin >> t;
    PRE.push_back(t);
  }
  for(int i = 0; i < n; i++){
    int t; cin >> t;
    IN.push_back(t);
    M[t] = i;
  }
  makePost(0, n-1);
  printPost(PRE[0]);
  cout << endl;
}