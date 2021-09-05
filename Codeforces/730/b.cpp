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

void solve(){
	ll n;
	cin >> n;
	vector <ll> a(n);
	for (auto &ai : a) cin >> ai;
	ll sum = 0;
	for (auto ai : a) sum += ai;

	cout << sum % n * (n - sum % n) << '\n';
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