#include <iostream>
#include <string>
#include <cstring>
#define RASENGAN ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

char andBit(char s, char t){
	if (s == '0' || t == '0'){
		return '0';
	}

	if (s == '?' || t == '?'){
		return '?';
	}
	return '1';
}

char orBit(char s, char t){
	if (s == '1' || t == '1'){
		return '1';
	}
	if (s == '?' || t == '?'){
		return '?';
	}
	return '0';
}

int main(){
	RASENGAN

	while(1){
		int n;
		cin >> n;
		if (n == 0){
			break;
		}

		char s[32];
		memset(s, '?', sizeof(s));
		while(n--){
			string t;
			cin >> t;
			if (t == "SET") {
				int i;
				cin >> i;
				i = 31 - i;
				s[i] = '1';
			}
			if (t == "CLEAR"){
				int i;
				cin >> i;
				i = 31 -i;
				s[i] = '0';
			}
			if (t == "AND"){
				int i, j;
				cin >> i >> j;
				i = 31 - i;
				j = 31 - j;
				s[i] = andBit(s[i], s[j]);
			}
			if (t == "OR"){
				int i, j;
				cin >> i >> j;
				i = 31 - i;
				j = 31 - j;
				s[i] = orBit(s[i], s[j]);
			}
		}

		for (char c : s){
			cout << c;
		}
		cout << '\n';
	}
	return 0;
}
