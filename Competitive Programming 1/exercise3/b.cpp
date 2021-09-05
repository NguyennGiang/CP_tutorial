#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(int tc) {
	int n; 
	cin >> n; 
	priority_queue <ll, vector<ll>, greater <ll>> q;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		q.push(x);
	}

	ll ans = 0ll; 

	for (int i = 1; i < n; i++){
		ll x = q.top();
		q.pop();
		ll y = q.top();
		q.pop();
		ans += x + y; 
		q.push(x + y);
	}

	cout << ans << endl;
}

int main(){

	ios_base::sync_with_stdio(0); cin.tie(0);

	int t; 
	cin >> t; 
	for (int i = 1; i <= t; i++){
		solve(i);
	}
	return 0;
}