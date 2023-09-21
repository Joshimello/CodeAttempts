#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main(){
  int n; cin >> n;

  vector<string> b = {"0", "1"};
  for(int i = 1; i < n; i++){
    vector<string> r = b;
    reverse(r.begin(), r.end());
    for(string& s : r){
      s += '1';
    }

    for(string& s : b){
      s += '0';
    }
    
    b.insert(b.end(), r.begin(), r.end());
  }

  for(string i : b){
    cout << i << endl;
  }
}