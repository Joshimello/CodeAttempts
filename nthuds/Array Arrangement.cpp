#include <iostream>
#include <vector>
using namespace std;
int main(){
  int T; cin >> T;
  while(T--){

    int n, q; cin >> n >> q;
    vector<char> info(n, 'M');
    vector<int> head;
    vector<int> tail;

    while(q--){
      char cmd; int t; cin >> cmd >> t;
      // cout << '[' << t << ']';
      if(cmd == 'H') head.push_back(t);
      else tail.push_back(t);
      info[t-1] = cmd;
    }

    vector<bool> visited(n);  
    for(int i = head.size()-1; i >= 0; i--){
      if(visited[head[i]-1]) continue;
      if(info[head[i]-1] != 'H') continue;
      cout << head[i] << ' ';
      visited[head[i]-1] = true;
    }

    for(int i = 0; i < n; i++){
      if(info[i] == 'M') cout << i+1 << ' ';
    }

    vector<int> temp;
    for(int i = tail.size()-1; i >= 0; i--){
      if(visited[tail[i]-1]) continue;
      if(info[tail[i]-1] != 'T') continue;
      temp.push_back(tail[i]);
      visited[tail[i]-1] = true;
    }

    for(int i = temp.size()-1; i >= 0; i--){
      cout << temp[i] << ' ';
    }

    cout << endl;
  }
}