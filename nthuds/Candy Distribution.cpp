#include <iostream>
#include <vector>
using namespace std;
bool f(int M, vector<int>& A, int m){
  long S = 0;
  for(int& i : A){
    S += (i+M-1)/M;
  }
  if(S <= m) return true;
  else return false;
}
int main(){
  vector<int> A;
  int n, m; cin >> n >> m;
  int mv = -1;
  for(int i = 0; i < n; i++){
    int t; cin >> t;
    A.push_back(t);
    mv = max(mv, t);
  }
  int L = 1, R = mv;
  while(L < R){
    int M = (L+R)/2;
    if(f(M, A, m)) R = M;
    else L = M+1;
  }
  cout << R << endl;
}