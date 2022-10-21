#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define mod 1000000007
#define oo 1000000000

const int N = 1e5 + 5;
int f[N][20];
ll pre[N];
int n, q, m;

int binarySearch(int x){
	int l = 1, r = x;
	int ans = -1;
	while(l <= r){
		int mid = (l + r) / 2;
		ll sum = pre[x] - pre[mid - 1];
		if (sum <= 1LL * m){
			r = mid - 1;
			ans = mid;
		}
		else l = mid + 1;
	}
	return ans;
}

int get(int u, int v){
	for (int i = 19; i >= 0 && u > 0; i--){
		if ((1 << i) <= v){
			u = f[u][i] - 1;
			v -= (1 << i);
		}
	}
	return u + 1;
}

void solve(){
	cin >> n >> q >> m;
	for (int i = 1; i <= n; i++){
		cin >> pre[i];
	}
	for (int i = 1; i <= n; i++){
		pre[i] = pre[i-1] + pre[i];
	}

	for (int i = 1; i <= n; i++){
		f[i][0] = binarySearch(i);
	}

	for (int j = 1; j < 20; j++){
		for (int i = 1; i <= n; i++){
			if (f[i][j-1] == 1){
				f[i][j] = 1;
			}
			else f[i][j] = f[f[i][j-1] - 1][j-1];
		}
	}

	while(q--){
		int u, v;
		cin >> u >> v;
		cout << get(u, v) << endl;
	}
	return ;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}
	return 0;
}

