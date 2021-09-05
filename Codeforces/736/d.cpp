#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector <int> a(n);
		for (int &ai : a) cin >> ai;

		vector <int> ans(n - 1);
		for (int i = 1; i < n; i++){
			ans[i] = abs(a[i] - a[i-1]);
		}

		int res = 0;
		for (int i = 0; i < n-1; i++){
			int tmp = 1;
			int j = i + 1;
			int cur = ans[i];
			while(j < n - 1&& __gcd(ans[j], cur) > 1){
				j++;
				cur = __gcd(ans[j], cur);
				tmp++;
			}
			res = max(res, tmp);
		}
		cout << res << endl;
	}
	return 0;
}