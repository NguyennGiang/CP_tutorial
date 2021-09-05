#include <bits/stdc++.h>

using namespace std;

int count_pair_sum_upto(long long x, long long a[], long long n) {
	int cnt = 0;
	int j = n - 1;
	for (int i = 0; i < n; i++){
		while(j > 0 && a[i] + a[j] >= x){ 
			j--;
		}
		cnt += max(0, j - i);
	}

	return cnt;
}

void solve(){
	long long n, l , r; 
	cin >> n >> l >> r; 

	long long a[n];
	for (int i = 0; i < n; i++) cin >> a[i];

	sort(a, a + n);
	
	cout << count_pair_sum_upto(r, a, n) - count_pair_sum_upto(l-1, a, n) << '\n';
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