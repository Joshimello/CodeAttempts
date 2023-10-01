#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int main(){
  int l1; cin >> l1;
  vector<int> n1(100, 0);
  for(int i = l1-1; i >= 0; i--){
    scanf("%1d", &n1[i]);
  }
  int l2; cin >> l2;
  vector<int> n2(100, 0);
  for(int i = l2-1; i >= 0; i--){
    scanf("%1d", &n2[i]);
  }

  vector<int> n3(101);
  for(int i = 0; i < 100; i++){
    n3[i] = n1[i] + n2[i];
    if(n3[i] >= 10){
      n3[i] -= 10;
      n3[i+1] += 1;
    }
  }

  int L;
  for(int i = 101; i > 0; i--){
    if(n3[i] != 0){
      L = i;
      break;
    }
  }

  for(int i = L-1; i >= 0; i--){
    cout << n3[i];
  }
  cout << endl;

}