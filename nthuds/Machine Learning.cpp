#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){
  int n, k; cin >> n >> k;
  vector<int> S, E;
  for(int i = 0; i < n; i++){
    int t; cin >> t;
    S.push_back(t);
  }
  for(int i = 0; i < n; i++){
    int t; cin >> t;
    E.push_back(t);
  }

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q, QQ;
  for(int i = 0; i < n; i++){
    Q.push({E[i], S[i]});
  }

  int c = 0;
  vector<vector<pair<int, int>>> SEL(k); 
  while(Q.size()){
    auto [e, s] = Q.top(); Q.pop();
    int p = -1, ge = -1;
    for(int i = 0; i < k; i++){
      if(SEL[i].empty()){
        p = i;
      }
      if(!SEL[i].empty() && s > SEL[i].back().first){
        if(SEL[i].back().first > ge){
          ge = SEL[i].back().first;
          p = i;
        }
      }
    }
    if(p != -1){
      SEL[p].push_back({e, s});
      // cout << p << ": " << s << ' ' << e << endl;
      c++;
    }
  }

  cout << c << endl;
}