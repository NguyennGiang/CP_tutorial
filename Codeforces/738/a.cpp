#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	int t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		vector <ll> v(n);
		for (ll &vi : v) cin >> vi;

		int ans = 1e9;
		for (ll i = 0; i < n; i++){
			for (ll j = 0; j < n; j++){
				for (ll k = 0; k <= j - i; k++){
					v[i+k] = (v[i + k] & v[j - k]);
				}
				int x = 1e9;
				for (int id = 0; id < n; id++){
					if (v[id] < x){
						x = v[id];
					}
				}
				ans = min(ans, x);
			}
		}
		cout << ans << endl;
	}	
	return 0;
}