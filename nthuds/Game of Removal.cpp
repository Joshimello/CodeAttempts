#include <iostream>
#include <vector>
using namespace std;
bool isSub(vector<char> S, vector<char> T){
  int pos = 0;
  for(char& i : S){
    if(T[pos] == i){
      if(++pos == T.size()) return true;
    }
  }
  return false;
}
vector<char> newT(vector<char>& T, int M, vector<int>& A){
  vector<char> nT = T;
  for(int i = 0; i < M; i++){
    nT[A[i]-1] = '#';
  }
  vector<char> nnT;
  for(char& i : nT){
    if(i == '#') continue;
    nnT.push_back(i);
  }
  return nnT;
}
int main(){
  int n, m; cin >> n >> m;
  vector<char> S;
  vector<char> T;
  vector<int> A;
  for(int i = 0; i < n; i++){
    char t; cin >> t;
    S.push_back(t);
  }
  for(int i = 0; i < m; i++){
    char t; cin >> t;
    T.push_back(t);
  }
  for(int i = 0; i < m; i++){
    int t; cin >> t;
    A.push_back(t);
  }
  int L = 1, R = m;
  while(L < R){
    int M = (L + R) / 2;

    vector<char> nT = newT(T, M, A);
    // for(char& i : nT) cout << i << ' ';
    // cout << endl;

    if(isSub(S, nT)) R = M;
    else L = M + 1;
  }

  cout << R << endl;
}