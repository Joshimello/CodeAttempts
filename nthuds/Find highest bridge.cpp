#include <iostream>
using namespace std;
int main(){
  int n; cin >> n;
  int max = -1;
  int idx = -1;
  for(int i = 0; i < n; i++){
    int t; cin >> t;
    if(t > max){
      max = t;
      idx = i;
    }
  }
  cout << idx + 1 << endl;
}