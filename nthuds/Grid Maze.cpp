#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <stack>
using namespace std;
int main(){
  int h, w; cin >> h >> w;
  char m[h][w];
  
  tuple<int, int, int> str;
  int endX, endY;

  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      char c; cin >> c;
      m[i][j] = c;
      if(c == 'A') str = {i, j, 0};
      if(c == 'B'){
        endX = i, endY = j;
        m[i][j] = '.';
      }
    }
  }

  bool found = false;
  int distance = 0;
  vector<char> path;

  queue<tuple<int, int, int>> q;
  q.push(str);
  while(q.size()){
    auto [x, y, d] = q.front();
    q.pop();

    if(m[x][y] == '#') continue;
    if(x == endX && y == endY){
      found = true;
      distance = d;
      break;
    }

    if(x+1 < h && m[x+1][y] == '.'){
      q.push({x+1, y, d+1});
      m[x+1][y] = 'D';
    }
    if(x-1 >= 0 && m[x-1][y] == '.'){
      q.push({x-1, y, d+1});
      m[x-1][y] = 'U';
    }
    if(y+1 < w && m[x][y+1] == '.'){
      q.push({x, y+1, d+1});
      m[x][y+1] = 'R';
    }
    if(y-1 >= 0 && m[x][y-1] == '.'){
      q.push({x, y-1, d+1});
      m[x][y-1] = 'L';
    }
  }

  if(found){
    cout << "YES" << endl;
    cout << distance << endl;

    // for(int i = 0; i < h; i++){
    //   for(int j = 0; j < w; j++){
    //     cout << m[i][j];
    //   }
    //   cout << endl;
    // }

    stack<char> path;
    int x = endX, y = endY;
    while(m[x][y] != 'A'){
      path.push(m[x][y]);
      if(m[x][y] == 'U') x++;
      else if(m[x][y] == 'D') x--;
      else if(m[x][y] == 'R') y--;
      else if(m[x][y] == 'L') y++;
    }

    while(path.size()){
      cout << path.top();
      path.pop();
    }

    cout << endl;
  } 
  else cout << "NO" << endl;
}