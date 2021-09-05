#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n; 
	cin >> n;
	int a[n];
	int sum = 0; 
	for (int i = 0; i < n; i++){
		cin >> a[i];
		sum += a[i];
	}

	if ((sum % n) != 0){
		cout << -1 << '\n';
	}
	else {
		int cnt = 0;
		int ans = sum / n;
		for (int i = 0; i < n; i++){
			if (a[i] > ans){
				cnt ++;
			}
		}
		cout << cnt << '\n';
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