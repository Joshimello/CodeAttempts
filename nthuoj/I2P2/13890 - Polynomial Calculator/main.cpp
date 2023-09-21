#include <bits/stdc++.h>
#include "function.h"
using namespace std;
void solve(){
    string tmp;
    getline(cin, tmp);
    stringstream ss(tmp);
    Function *now = Function::parse(ss);
    int q; cin >> q;
    while(q--){
        double x; cin >> x;
        cout << fixed << setprecision(2) << now -> eval(x) << endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    solve();
    return 0;
}
