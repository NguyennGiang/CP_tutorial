#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define mod 998244353
#define oo 1000000000

int bit(int n){
	return __builtin_popcount(n);
}

int count(string &s,int tmp, int i, int m){
  for (int j = i + m; j < s.size(); j++){
    int x = s[j] - 'a';
    tmp |= (1 << x);
  }
  return bit(tmp);
}

void solve(){
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int ans = 0;
	for (int i = 0; i <= n; i++){
    int tmp = 0;
    for (int j = 0; j < i; j++){
      int x = s[j] - 'a';
      tmp |= (1 << x);
    }
    if (bit(tmp) > k) break;
    int l = 1, r = n - i;
    int res = 0;
    while(l <= r){
      int m = (l + r) / 2;
      if (count(s, tmp, i, m) <= k){
        res = m;
        r = m - 1;
      }
      else l = m + 1;
    }
    ans += n - (i + res) + 1;
	ans %= mod;
  }
	cout << ans << endl;
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
