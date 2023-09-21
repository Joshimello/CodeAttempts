#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){
  int n; cin >> n;
  queue<int> v;
  for(int i = 0; i < n; i++){
    int t; cin >> t;
    v.push(t);
  }
  int a = 0;

  while(v.size()){
    int m = v.front(); v.pop();
    queue<int> vv;
    while(v.size()){
      if(v.front() > m){
        cout << v.front() << ' ';
        m = v.front();
        v.pop();
      }
      else {
        vv.push(v.front());
        v.pop();
      }
    }
    v = vv;
    a++;
    cout << endl;
  }


  //   while(v.size()){
  //     if(v.front() != i) vv.push(v.front());
  //     else i++;
  //     v.pop();
  //   }
  //   v = vv;
  //   vv = {};
  //   a++;
  // }
  cout << a << endl;
}