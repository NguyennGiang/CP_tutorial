#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;

		if (n % 2 == 0){
			cout << 2 << " " << 4 << endl;
		}
		else {
			cout << 2 << " " << n-1 << endl;
		}
	}
	return 0;
}