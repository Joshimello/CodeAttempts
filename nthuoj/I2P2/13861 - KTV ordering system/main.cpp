#include <iostream>
#include <cstdlib>
#include "function.h"
using namespace std;

void print(song *st, song *en){
    song *now = st;
    while(now != en){
        cout << now -> num << ' ';
        now = now -> next;
    }
    cout << "\n";
}

void solve(){
    int n;
    cin >> n;
    ordering_system os;
    os.initialize();
    while(n--){
        string op;
        int x;
        cin >> op;
        if(op == "order"){
            cin >> x;
            os.order(x);
        }else if(op == "insert"){
            cin >> x;
            os.insert(x);
        }else if(op == "play"){
            os.play();
        }else{
            os.show();
        }
    }
    os.destroy();
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}

