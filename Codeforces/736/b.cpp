#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		string s1, s2;
		cin >> s1 >> s2;

		vector <int > a(n);
		vector <int> b(n);



		for (int i = 0; i < n; i++){
			a[i] = (s1[i] == '1');
			b[i] = (s2[i] == '1');
		}

		int res = 0;
		for (int i = 0; i < n; i++){
			if (b[i] == 0){
				continue;
			}

			if (a[i] == 0){
				res++;
				continue;
			}

			if (i > 0 && a[i-1] == 1){
				res++;
				a[i-1] = 2;
				continue;
			}

			if (i < n - 1 && a[i + 1] == 1){
				res++;
				a[i + 1] = 2;
				continue;
			}
		}
		cout << res << endl;
	}
	return 0;
}