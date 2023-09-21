#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  long long n; cin >> n;
  long long a[n];
  for(long long i = 0; i < n; i++){
    cin >> a[i];
  }
  sort(a, a+n);

  long long s1 = 0, s2 = 0;
  for(long long i = 0; i < n; i++){
    s1 += abs(a[n/2-1] - a[i]);
  }

  for(long long i = 0; i < n; i++){
    s2 += abs(a[n/2] - a[i]);
  }

  if(s1 <= s2){
    cout << a[n/2-1] << " " << s1 << endl;  
  }
  else {
    cout << a[n/2] << " " << s2 << endl;  
  }

}