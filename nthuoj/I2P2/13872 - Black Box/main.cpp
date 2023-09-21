#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
  map<int, int> m;
  int n; cin >> n;
  while(n--){
    int o; cin >> o;
    if(o == 1){
      int k, x; cin >> k >> x;
      m[x] += k;
    }
    else if(o == 2){
      int k, x; cin >> k >> x;
      m[x] -= k;
      if(m[x] <= 0) m.erase(x);
    }
    else if(o == 3){
      int x; cin >> x;
      cout << m[x] << endl;
      if(m[x] <= 0) m.erase(x);
    }
    else if(o == 4){
      if(m.size() == 0) cout << "The box is empty." << endl;
      else cout << (--m.end())->first << endl;
    }
    else if(o == 5){
      if(m.size() == 0) cout << "The box is empty." << endl;
      else cout << m.begin()->first << endl;
    }
  }
}