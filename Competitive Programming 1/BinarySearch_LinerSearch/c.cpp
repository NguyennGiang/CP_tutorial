/*
	--> BINHPHUONG (THT 2017)
*/
#include <iostream>
#include <math.h>
#define ll long long int

using namespace std;

ll count(ll s){
    ll cnt = 0;
    ll ed = sqrt(s);
    for (ll i = 1; i <= ed; i++){
        ll tmp = sqrt(s - i * i);
        cnt += tmp;
    }
    return cnt;
}

int main(){

	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	ll k;
	cin >> k;

	ll l = 2;
	ll r = 2 * pow(10, 12);
	while(l < r){
		ll m = l + ((r - l) >> 1);
		if (count(m) >= k){
			r = m;
		}
		else l = m + 1;
	}

	cout << l << '\n';
	return 0;
}