#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
int main(){
  int n; cin >> n;
  long long a = 0; long long b = 1;
  for(int i = 2; i <= n; i++){
    long long t = (a + b) % 1000000007;
    a = b; b = t;
  }
  if(n == 0) b = 0;
  cout << b << endl;
}