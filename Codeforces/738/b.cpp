#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--){
		string s;
		int n;
		cin >> n >> s;
		for (int i = 0; i < n; i++){
			if (s[i] != '?'){
				for (int j = i - 1; j >= 0; j--){
					if (s[j] != '?'){
						continue;
					}
					if (s[j + 1] == 'R'){
						s[j] = 'B';
					}
					else if (s[j + 1] == 'B') {
						s[j] = 'R';
					}
				}
				for (int j = i + 1; j < n; j++){
					if (s[j] != '?'){
						continue;
					}
					if (s[j-1] == 'R'){
						s[j] = 'B';
					}
					else if (s[j - 1] == 'B'){
						s[j] = 'R';
					}
				}
			}
			else continue;
		}
		if (s[0] == '?'){
			for (int i = 0; i < n; i++){
				if (i % 2 == 0){
					s[i] = 'R';
				}
				else s[i] = 'B';
			}
		}
		cout << s << endl;
	}
	return 0;
}