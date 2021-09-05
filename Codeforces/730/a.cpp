#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
#include <math.h>
#include <cstring>
#include <string.h>
#define RASENGAN ios_base::sync_with_stdio(0); cin.tie(0);
#define f first
#define s second
#define ll long long

using namespace std;

typedef pair <int, int> pii;
const ll mod = 1e9 + 7;
const ll INF = 1e15;

ll gcd (ll a, ll b){
	if (b == 0){
		return a;
	}
	else return gcd(b, a % b);
}
void solve(){
	ll a, b;
	cin >> a >> b;
	if (a == b){
		cout << "0 0\n";
	}
	else {
		if (a > b){
			swap(a, b);
		}
		ll res = b - a;
		cout << res << " " << min(a % res, res - a % res) << '\n';
	}
}

int main(){
	RASENGAN;
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}