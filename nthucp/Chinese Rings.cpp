#include <iostream>
using namespace std;
int n;
void owo(int);
void uwu(int i){
  if(i < 1) return;
  if(i == 1){
    cout << "Move ring 1 out" << endl;
    return;
  }
  uwu(i-2);
  cout << "Move ring " << i << " out" << endl;
  owo(i-2);
  uwu(i-1);
}
void owo(int i){
  if(i < 1) return;
  if(i == 1){
    cout << "Move ring 1 in" << endl;
    return;
  }
  owo(i-1);
  uwu(i-2);
  cout << "Move ring " << i << " in" << endl;
  owo(i-2);
}
int main(){
  cin >> n;
  uwu(n);
}