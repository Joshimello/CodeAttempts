#include <iostream>
#include <algorithm>
using namespace std;

int n, arr[200000], j;
void postorder(int l, int r){
  if(j >= n) return;
  if(arr[j] < l || arr[j] > r) return;
  
  int t = arr[j++];
  postorder(l, t);
  postorder(t, r);
  cout << t << " ";
}

int main(){
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> arr[i];
  postorder(0, 1e9);
}