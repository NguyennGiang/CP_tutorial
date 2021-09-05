#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1e9 + 1;
int n;

bool bs(vector <int> &a, int x, int j){
	if (a[j] == x){
		return (j > 0 && a[j-1] == x);
	}

	int l = 0;
	int r = a.size() - 1;
	while(l <= r){
		int m = (l + r) / 2;

		if (a[m] == x){
			return true;
		}
		if (a[m] > x){
			r = m - 1;
		}
		else l = m + 1;
	}

	return false;
}

int main(){
	cin >> n;

	vector <int> a(n);

	for (int &ai : a) cin >> ai;

	sort(a.begin(), a.end());

	vector <int> f(n, 0);

	int res = 0;
	for (int i = 0; i < n; i++){
		for (int j = i - 1; j >= 0; j--){
			if (bs(a, a[i] - a[j], j)){
				f[i] = max(f[i], f[j]);
			}
		}
		f[i]++;	
		res = max(res, f[i]);
	}
	for (int fi : f) cout << fi << " ";

	return 0;
}