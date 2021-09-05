/*
	--> CAKE (PTNK 2014-2015)
*/
#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;
	vector <int> a(n);
	for (int &ai : a) cin >> ai;

	//binary

	sort(a.begin(), a.end(), greater <int>());
	int l = n / 2;
	int r = n;

	while (l < r){
		int m = (r + l) / 2;
		int oce = true;
		for (int i = 0; i < n - m; i++){
			if (a[i] < 2 * a[i + m]) {
				oce = false;
			}
		}

		if (oce) r = m;
		else l = m + 1;
	}

	cout << r << '\n';
	return 0;
}