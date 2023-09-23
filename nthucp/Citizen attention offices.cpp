#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
int main(){
  int T; cin >> T;
  while(T--){
    int n; cin >> n;
    vector<tuple<int, int, int>> v;
    for(int i = 0; i < n; i++){
      int x, y, p; cin >> x >> y >> p;
      v.push_back({x, y, p});
    }

    int mx = 1e9;
    vector<int> mxo;

    for(int o1 = 0; o1 < 25; o1++)
      for(int o2 = o1+1; o2 < 25; o2++)
        for(int o3 = o2+1; o3 < 25; o3++)
          for(int o4 = o3+1; o4 < 25; o4++)
            for(int o5 = o4+1; o5 < 25; o5++){
              int c = 0;
              for(auto [x, y, p] : v){
                int mn = 1e9;
                for(int o : {o1, o2, o3, o4, o5}){
                  mn = min(mn, abs(o/5-x)+abs(o%5-y));
                }
                c += mn*p;
              }
              if(c < mx){
                mx = c;
                mxo = {o1, o2, o3, o4, o5};
              }
            }

    for(int i : mxo){
      cout << i << ' ';
    }
    cout << endl;

  }
}