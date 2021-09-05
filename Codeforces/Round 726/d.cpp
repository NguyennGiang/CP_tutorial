#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin >> n;

	if ( n % 2 == 1){
		cout << "Bob\n";
		return;
	}

	int cnt = 0;
	while (n % 2 == 0){
		cnt++;
		n /= 2;
	}

	if (n > 1){
		cout << "Alice\n";
		return;
	}

	if (cnt % 2 == 0){
		cout << "Alice\n";
	}
	else {
		cout << "Bob\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t; 
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}