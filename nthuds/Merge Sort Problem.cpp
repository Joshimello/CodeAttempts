#include <iostream>
#include <vector>
using namespace std;

using Iter = vector<long long>::iterator;

void merge(Iter L, Iter M, Iter R) {
  static vector<long long> buff;
  buff.clear();
  Iter i = L, j = M;
  while (i != M && j != R) {
    if (*i < *j) {
      buff.emplace_back(*i), i++;
    } else {
      buff.emplace_back(*j), j++;
    }
  }
  for (; i != M; i++) buff.emplace_back(*i);
  for (; j != R; j++) buff.emplace_back(*j);
  copy(buff.begin(), buff.end(), L);
}

void merge_sort(Iter L, Iter R) {
  if (L+1 >= R) {
    return;
  } else {
    Iter M = L + (R - L) / 2;
    merge_sort(L, M);
    merge_sort(M, R);
    merge(L, M, R);
  }
}

int main(){
  int n; cin >> n;
  vector<long long> v;
  for(int i = 0; i < n; i++){
    long long a; cin >> a;
    v.push_back(a);
  }

  vector<long long>::iterator L = v.begin();
  vector<long long>::iterator R = v.end();

  merge_sort(L, R);

  for(int i = n - 1; i >= 0; i--){
    cout << v[i] << ' ';
  }
  cout << endl;
}