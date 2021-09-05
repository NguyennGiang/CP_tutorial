#include <iostream>
#include <vector>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector <int> a(2 * n);
		for (auto &ai : a) cin >> ai;

		int odd = 0;
		for (int ai : a){
			if (ai % 2 == 1){
				odd++;
			}
		}
		if (odd == n){
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
		}
	}
	return 0;
}