#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		long long n;
		cin >> n;
		long long ans = 0;
		if (n < 6){
			ans = 15;
		}
		else {
			if (n % 2 != 0){
				n ++;
			}
			ans = (n * 5) / 2;
		}
		cout << ans << endl;

	}
	return 0;
}