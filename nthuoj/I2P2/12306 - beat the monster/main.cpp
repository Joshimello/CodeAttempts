#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
int v[15][301][401] = {0};
int main(){
  int L, HP, MHP, MDMG;
  vector<int> DMG, HEAL;
  cin >> L >> HP >> MHP >> MDMG;

  for(int i = 0; i < L; i++){
    int tDMG, tHEAL;
    cin >> tDMG >> tHEAL;
    DMG.push_back(tDMG);
    HEAL.push_back(tHEAL);
  }

  queue<tuple<int, int, int, int>> q;
  q.push({0, 0, HP, MHP});

  while(!q.empty()){
    int cS, cL, cHP, cMHP;
    tie(cS, cL, cHP, cMHP) = q.front();
    q.pop();

    // printf("L %d, HP %d, MHP %d, DMG %d, HEAL %d\n", cL, cHP, cMHP, DMG[cL], HEAL[cL]);

    if(cMHP <= 0){
      cout << cS << endl;
      return 0;
    }

    if(cHP <= 0) continue;
    if(v[cL][cHP][cMHP]) continue;

    q.push({cS + 1, cL, cHP - MDMG, cMHP - DMG[cL]});
    q.push({cS + 1, cL, min(cHP + HEAL[cL], HP) - MDMG, cMHP});
    if(cL + 1 < L) q.push({cS + 1, cL + 1, cHP - MDMG, cMHP});

    v[cL][cHP][cMHP] = 1;
  }

  cout << -1 << endl;
}