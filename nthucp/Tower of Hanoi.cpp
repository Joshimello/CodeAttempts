#include <iostream>
using namespace std;
int cc;
void many(int n){
  if(n == 0) return;
  many(n-1);
  cc++;
  many(n-1);
}
void hanoi(int n, int a, int b, int c){
  if(n == 0) return;
  hanoi(n-1, a, c, b);
  cout << a << ' ' << c << endl;
  hanoi(n-1, b, a, c);
}
int main(){
  int n; cin >> n;
  many(n);
  cout << cc << endl;
  hanoi(n, 1, 2, 3);
}