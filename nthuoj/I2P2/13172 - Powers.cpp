#include<iostream>
#include<string>
#include<cmath>

using namespace std;
class special_power{
public:
    int n;
    special_power(int x);
    int fpow(int x);
    int fpow(int x, int m);
    int fpow();
    string fpow(string s);
    string fpow(string s, int m);
};

special_power::special_power(int x){
    n = x;
}

int special_power::fpow(int x){
    return (unsigned long long)pow(x, n) % 880301;
}

int special_power::fpow(int x, int m){
    return (unsigned long long)pow(x, n) % m;
}

int special_power::fpow(){
    return (unsigned long long)pow(2, n) % 880301;
}

string store;

string special_power::fpow(string s)
{
    string str = "";
    for(int i = 0; i < s.size(); i++){
        string sub_str(n, s[i]);
        str = str + sub_str;
    }
    store = str;
    return str;
}

string special_power::fpow(string s, int m)
{
    string str = store;
    if(str.size() >= m)
        str = str.substr(0, m);
    return str;
}


using namespace std;
int main(){
    int x, n, m;
    string s;
    cin >> x >> n >> m >> s;
    special_power sp(n);
    cout << sp.fpow(x) << "\n";
    cout << sp.fpow(x, m) << "\n";
    cout << sp.fpow() << "\n";
    cout << sp.fpow(s) << "\n";
    cout << sp.fpow(s, m) << "\n";
}
