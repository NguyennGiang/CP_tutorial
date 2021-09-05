/*
	--> JROBOT (Chuyên tin THPT TPHCM 2013-2014)
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	int a[n * m];
	for (int i = 0; i < n*m; i++){
		cin >> a[i];
	}
	int x, y;
	cin >> x >> y;

	int st = a[(x - 1) * m + y - 1];
	//cout << st << endl;

	sort(a, a + n * m);
	int step = 0;
	for (int i = 0; i < m * n; i++){
		if (a[i] > st){
			step++;
			st = a[i];
		}
	}

	cout << step;
	return 0;
}