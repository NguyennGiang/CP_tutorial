/*
	--> Recycle Numbers (Qualification round 2012 - Google code Jam);
	
*/

#include <iostream>
#include <math.h>

using namespace std;

int numDigit(int n){
	if (n < 10){
		return 1;
	}
	return numDigit(n / 10) + 1;
}

void solve(int tc){
	int a, b;
	cin >> a >> b;

	int m = numDigit(a);
	int p[10];
	p[0] = 1;
	for (int i = 1; i < 10; i++) p[i] = p[i-1] * 10;
	int cnt = 0;
	
	for (int n = a; n <= b; n++){
		for (int i = 1; i < m; i++){
			int ans = n % p[i] * p[m-i] + n / p[i];
			if (ans == n){
				break;
			}

			if (ans <= b && n < ans){
				cnt++;
			}
		}
	}
	cout << "Case #" << tc << ": " << cnt << '\n';
}

int main(){
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++){
		solve(i);
	}
	return 0;
}