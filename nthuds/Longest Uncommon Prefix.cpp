#include <iostream>
#include <vector>
using namespace std;
int main(){
  int n; cin >> n;
  vector<char> a;
  for(int i = 0; i < n; i++){
    char c; cin >> c;
    a.push_back(c);
  }
  for(int i = 1; i < n; i++){
    int s = 0;

    for(int j = 0; j < n-i; j++){
      if(a[j] == a[j+i]) break;
      s++;
    }

    cout << s << endl;
  }
}