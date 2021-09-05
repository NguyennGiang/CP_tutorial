/*
--> SOk (THT 2015)
*/

#include <iostream>
#include <math.h>
#define ll long long

using namespace std;

const ll a = 3, b = 5, c = 7;

ll count(ll x){
	return x / a + x / b + x / c - x / (a * c) - x / (a * b) - x / (b * c) + x / (a * b * c);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t, k; 
	cin >> t >> k;

	ll l = 3;
	ll r = 3 * k;
	while (l < r){
		ll m = l + (r - l) / 2;

		if (count(m) >= k){
			r = m;
		}
		else l = m + 1;
	}

	cout << l;
	return 0; 
}