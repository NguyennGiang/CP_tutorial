 #include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector <int> v(n);
		for (int &vi : v) cin >> vi;

		int x = -1;
		if (v[0] == 1){
			cout << n + 1 << " ";
			for (int i = 0; i < n; i++){
				cout << i + 1 << " ";
			}
		}
		else if (v[n-1] == 0){
			for (int i = 0; i <= n; i++){
				cout << i + 1 << " ";
			}
		}
		else {
			for (int i = 0; i + 1 < n; i++){
				if (v[i] == 0 && v[i + 1] == 1){
					for (int j = 0; j < i + 1; j++){
						cout << j + 1 << " ";
					}
					cout << n + 1 << " ";
					for (int j = i + 1; j < n; j++){
						cout << j + 1 << " ";
					}
					break;
				}
			}
		}
		cout << '\n';
	}
	return 0;
}