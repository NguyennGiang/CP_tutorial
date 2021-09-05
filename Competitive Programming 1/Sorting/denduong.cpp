/*
	--> @Descriptionn
		- Name: DENDUONG (Chuyên tin THPT TPHCM 2015-2016)
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int n, L;
	cin >> n >> L;
	long long a[n];
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}

	sort(a, a + n);

	double res = max(a[0], L - a[n-1]);
	for (long long i = 1; i < n; i++){
		res = max(res, (a[i] - a[i-1]) / 2.00);
	}

	printf("%.2lf\n", res);
	return 0;
}