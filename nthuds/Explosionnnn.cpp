#include <iostream>
#include <queue>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m; cin >> n >> m;
  priority_queue<pair<int, int>> Q;
  for(int i = 0; i < n; i++){
    int d, c; cin >> d >> c;
    Q.push({c, d});
  }

  priority_queue<int> A;

  for(int i = 0; i < n; i++){
    while(Q.size()){
      auto [c, d] = Q.top();
      if(c < m) break;
      Q.pop();
      A.push(d);
    }

    if(A.size() == 0){
      cout << -1 << endl;
      return 0;
    }

    m -= A.top();
    A.pop();

    if(m <= 0){
      cout << i+1 << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}