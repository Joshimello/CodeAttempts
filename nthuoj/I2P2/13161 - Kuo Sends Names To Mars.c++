#include <iostream>
#include <string>
using namespace std;

int main() {
	int ans = 0;
	string s;
	cin >> s;
	
	for(int i = 1; s[i] != '\0'; i++){
		if(s[i] == s[i-1] || (s[i] == s[i-2] && i > 1)){
			s[i] = 'X';
			ans++;
		}
	}

	cout << ans << endl;
}