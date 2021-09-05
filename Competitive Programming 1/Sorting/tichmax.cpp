/*
	--> TICHMAX (Chuyên tin PTNK 2007-2008)
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector <int> a(n);
	for (auto &ai : a) cin >> ai;

	sort (a.begin(), a.end());

	cout << max(1LL * a[n-1] * a[n-2] * a[n-3],
				1LL * a[n - 1] * a[0] * a[1]);
	return 0;	
}