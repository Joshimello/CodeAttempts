#include <iostream>
#include <map>
using namespace std;
int main(){
  int n; cin >> n;
  map<int, int> v;
  for(int i = 0; i < n; i++){
    int t; cin >> t;
    v[t]++;
    if(v[t] == 2){
      cout << t;
      return 0;
    }
  }
}