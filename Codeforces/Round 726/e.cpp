#include <bits/stdc++.h>

using namespace std;

string get(string s, int k){
	while(int(s.size()) < k){
		s = s + s;
	}
	while (int(s.size()) > k){
		s.pop_back();
	}
	return s;
}

void solve(){
	int n, k;
	string s;

	cin >> n >> k;
	cin >> s;

	string pre = "";
	pre += s[0];

	string mn = get(pre, k);

	for (int i = 1; i < n; i++){
		if (s[i] > s[0]) break;
		pre += s[i];
		mn = min(mn, get(pre, k));
	}

	cout << mn << endl;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	solve();
	return 0;
}