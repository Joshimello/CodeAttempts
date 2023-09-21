#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(){
  string str;
  while(getline(cin, str)){

    for(int i = 0; i < str.length(); i++){
      str[i] = toupper(str[i]);
    }

    stringstream s(str);
    string arr[1000], temp, acro;
    int i = 0;
    while(getline(s, temp, ' ')){
      arr[i++] = temp;
      acro += temp[0];
    }

    cout << (arr[0] == acro ? "o'_'o" : "QQ") << endl;
  }
}