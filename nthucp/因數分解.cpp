#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  long long n; cin >> n;
  long long e = sqrt(n);
  stack<long long> s;
  if(n > 1) cout << 1 << ' ';
  for(long long i = 2; i <= e; i++){
    if(n % i == 0){
      cout << i << ' ';
      if(i != n/i) s.push(n/i);
    }
  }
  while(s.size()){
    cout << s.top() << ' ';
    s.pop();
  }
  cout << n << ' ';
}