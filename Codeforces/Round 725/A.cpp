#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin >> n;
	int a[n];
	int x, y; 

	for (int i = 0; i < n; i++){
		cin >> a[i];
		if (a[i] == 1) x = i; 
		if (a[i] == n) y = i;
	}

	if (x > y){
		swap(x, y);
	}

	cout << min(y + 1, min(n - x, x + 1 + n - y)) << '\n';

	

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