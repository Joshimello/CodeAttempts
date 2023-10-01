#include <iostream>
#include <string>
using namespace std;
int main(){
  int ans = 0;
  string s; cin >> s;
  for(int i = 3; i <= s.size(); i++){
    for(int j = 0; j <= s.size()-i; j++){

      // for(int k = 0; k < i; k++){
      //   cout << s[j+k];
      // }
      // cout << endl;

      int L = j, R = j+i-1;
      int ok = 1;
      while(L < R){
        if(s[L] != s[R]){
          ok = 0;
          break;
        }
        L++; R--;
      }

      if(ok) ans++;
    }
  }

  cout << ans << endl;
}