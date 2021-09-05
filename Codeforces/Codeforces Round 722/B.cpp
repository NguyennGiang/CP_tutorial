#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0);
#define ll long long
#define pb push_back

using namespace std; 

int main(){
	fast_io
	int t; 
	cin >> t; 
	while(t--){
		int n; 
		vector <int> v; 
		cin >> n;
		for (int i = 0; i < n; i++) {
			int num; 
			cin >> num; 
			v.pb(num);
		}
		sort(v.begin(), v.end());
		int ans = 0; 
		vector <int> pos;
		for (int i = 0; i < n; i++){
			if (v[i] <= 0){
				ans++;
			}
			else {
				pos.pb(v[i]);
			}
		}
		sort(pos.begin(), pos.end());
		if (pos.size() > 0){
			int gap = pos[0];
			bool flag = 1; 
			for (int i = 1; i < n; i++){
				if (v[i] <= 0){
					if (v[i] - v[i-1] < gap) flag = 0;
				}
			}
			if (flag) ans++;
		}
		cout << ans << '\n';
	}
	return 0;
}