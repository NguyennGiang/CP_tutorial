#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n; 
	cin >> n; 
	int a[n];
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}

	sort(a, a + n);
	if (n == 2){
		cout << a[0] << " " << a[1] << '\n';
		return;
	}

	int dis = 1e9;
	int m;
	for (int i = 1; i < n; i++){
		if (a[i] - a[i-1] < dis){
			dis = a[i] - a[i-1];
			m = i; 
		}
	}
	for (int i = m; i < n; i++){
		cout << a[i] << " ";
	}
	for (int i = 0; i < m; i++){
		cout << a[i] << " ";
	}
	cout << '\n';
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