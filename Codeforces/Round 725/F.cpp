#include <bits/stdc++.h>

using namespace std;

int count(int x){
	int cnt = 0; 
	while(x > 0){
		cnt += x;
		x /= 10;
	}
	return cnt;
}

void solve(){
	int l, r;
	cin >> l >> r;
	cout << count(r) - count(l) << '\n';
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t; 
	cin >> t;
	for (int i = 1; i <= t; i++){
		solve ();
	}
	return 0;
}