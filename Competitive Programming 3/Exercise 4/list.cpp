#include<bits/stdc++.h>
using namespace std;

vector<int> d;

void divide(int p){
	d.clear();
	for (int i = 2; i * i <= p; i++){
		if (p % i == 0){
			d.push_back(i);
			while(p % i == 0) p /= i;
		}
	}
	if (p > 1) d.push_back(p);
}

int work(int x){
	int res = 0;
	for (int i = 1; i < (1 << d.size()); i++){
		int s = 1, n = 0;
		for (int j = 0; j < d.size(); j++){
			if (i & (1 << j)){
				s *= d[j];
				n = 1 - n;
			}
		}
		if (n) res += x / s;
		else res -= x / s;
	}
	return res;
}

void solve(){
	int x, p, k;
	cin >> x >> p >> k;
	divide(p);
	k = k + x - work(x);
	int l = x + 1, r = 1e9;
	while(r > l){
		int m = l + r >> 1;
		if (m - work(m) < k) l = m + 1;
		else r = m;
	}
	cout << l << endl;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
