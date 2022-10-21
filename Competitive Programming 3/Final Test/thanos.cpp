#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define mod 1000000009
#define oo 1000000000
typedef pair<int, int> pii;

const int N = 200005;

ll powMod(ll b, ll p){ // p ^ b mod m;
	ll res = 1;
	while(p){
		if (p & 1) res = res * b % mod;
		b = b * b % mod;
		p >>= 1;
	}
	return res;
}

ll fac[N], inv[N];
void init(int n){
	fac[0] = 1;
	inv[0] = 1;
	for (int i = 1; i <= n; i++){
		fac[i] = fac[i-1] * i % mod;
		inv[i] = powMod(fac[i], mod - 2);
	}

}

ll C(int n, int m){
	return n < m ? 0 : fac[n] * inv[m] % mod * inv[n - m] % mod;
}

int n, m, k;
pii a[N];
int f[N];

void solve(){
	cin >> n >> m >> k;
	init(n + m);

	for (int i = 1; i <= k; i++){
		cin >> a[i].fi >> a[i].se;
	}
	a[++k] = {n, m};
	sort(a + 1, a + k + 1);

	for (int i = 1; i <= k; i++){
		f[i] = C(a[i].fi - 1 + a[i].se - 1, a[i].fi - 1);
		for (int j = 1; j < i; j++){
			if (a[j].se > a[i].se) continue;
			f[i] = (f[i] -
				C(a[i].fi - a[j].fi + a[i].se - a[j].se, a[i].fi - a[j].fi) * f[j]) % mod;
		}
	}
	cout << (f[k] + mod) % mod << endl;
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

