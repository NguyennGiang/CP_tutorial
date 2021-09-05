#include <bits/stdc++.h>

using namespace std;

char chars[26];

void solve(){
	string s;
	cin >> s;
	int n = s.length();
	
	vector <bool> cnt(n, 0);

	string ans = "YES";

	for (char c : s){
		cnt[c - 'a'] = 1;
	}

	for (int i = 0; i < n; i++){
		if (cnt[i] != 1){
			ans = "NO";
		}
	}
	for (int i = 1; i < n - 1; i++){
		if(s[i] > s[i-1] && s[i] > s[i+1]){
			ans	= "NO";
		}
	}
	cout << ans << '\n';

}

int main(){
	int t;
	cin >> t;
	for (int i = 0; i < 26; i++){
		chars[i] = 'a' + i;
	}
	while(t--){
		solve();
	}
	return 0;
}