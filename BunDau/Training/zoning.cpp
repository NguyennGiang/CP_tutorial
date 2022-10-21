#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define mod 1000000007
#define oo 1000000000

void solve(){
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	for (int &x : a) cin >> x;
	int l = 0;
	int r = 0;
	int res = 0;
	int sum = 0;
	while(r < n){
		if (sum < x){
			sum += a[r];
			r++;
		}
		if (sum > x){
			sum -= a[l];
			l++;
		}
		if (sum == x){
			res ++;
			sum += a[r];
			r++;
			sum -= a[l];
			l++;
		}
	}
	cout << res << endl;
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

