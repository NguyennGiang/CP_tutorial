#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
#include <math.h>
#define RASENGAN ios_base::sync_with_stdio(0); cin.tie(0);
#define f first
#define s second
#define ll long long int
#define mod 1000000007

using namespace std;

int main(){
	RASENGAN;
	
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;

		ll res = 0;
		ll lcm = 1;

		for (ll i = 2; ; i ++){
			if (lcm > n) break;

			ll L = n / lcm;
			lcm = (lcm * i) / __gcd(lcm, i);
			ll R = n / lcm;
			ll add = ((L - R) * i) % mod;
			res = (res + add) % mod;
		}

		cout << res << '\n';
	}
	return 0;

}