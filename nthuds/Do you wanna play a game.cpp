#include <iostream>
#include <vector>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int test; cin >> test;
  while(test--){

    int n, k; cin >> n >> k;
    vector<int> tokill(n+1);
    for(int i = 0; i <= n; i++)
      tokill[i] = i+1;

    vector<int> dead(n+1, 0);

    while(k--){
      int q; cin >> q;
      if(dead[q]){
        cout << "Penguin07 QQ\n";
        continue;
      }
      while(dead[tokill[q]]){
        tokill[q]++;
      }
      if(tokill[q] > n){
        cout << "Penguin07 QQ\n";
        continue;
      }
      cout << tokill[q] << '\n';
      dead[tokill[q]] = 1;
    }

  }
}