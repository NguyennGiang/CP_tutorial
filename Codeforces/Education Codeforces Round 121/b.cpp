#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define mod 1000000007
#define oo 1000000000

void solve(){
	string s;
	cin >> s;
	for (int i = s.size() - 1; i > 0; i--){
		if (s[i - 1] - '0' + s[i] - '0' >= 10){
			int tmp = s[i - 1] - '0' + s[i] - '0';
			s[i-1] = tmp / 10 + '0';
			s[i] = tmp % 10 + '0';
			cout << s << endl;
			return;
		}
	}

	int x = s[0] - '0' + s[1] - '0';
	s.erase(s.begin());
	s[0] = x + '0';
	cout << s << endl;
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}

