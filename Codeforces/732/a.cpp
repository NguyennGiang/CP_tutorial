#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

void solve(){
	int n;
	cin >> n;
	int sum_a = 0;
	int sum_b = 0;
	vector <int> a(n);
	vector <int> b(n);
	for (int i = 0; i < n; i++){
		cin >> a[i];
		sum_a += a[i];
	}

	for (int i = 0; i < n; i ++){
		cin >> b[i];
		sum_b += b[i];
	}

	if (sum_a != sum_b){
		cout << -1 << '\n';
		return;
	}
	vector <int> diff(n);
	for (int i = 0; i < n; i++){
		diff[i] = a[i] - b[i];
	}

	vector <pair<int, int>> res;
	while(1){
		int x = -1, y = -1;
		for (int i = 0; i < n; i++){
			if (diff[i] > 0){
				x = i;
			}
			else if (diff[i] < 0){
				y = i;
			}
		}

		if (x < 0) break;

		diff[x]--;
		diff[y]++;

		res.push_back({x, y});	
	}

	cout << res.size() << '\n';

	for (auto item : res) cout << item.f + 1 << " " << item.s + 1 << '\n';
}

int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}
