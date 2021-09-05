#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
#include <math.h>
#define RASENGAN ios_base::sync_with_stdio(0); cin.tie(0);
#define f first
#define s second
#define ll long long
#define pii pair <int ,int>

using namespace std;

int main(){
	RASENGAN

	ll n;
	cin >> n;
	vector <pair <ll, ll>> v(n);
	ll tot = 0;
	for (auto &vi : v) cin >> vi.s >> vi.f, tot += vi.s;
	
	sort(v.begin(), v.end(), greater <pair <ll, ll>>());
	
	int l = 0, r = n - 1;
	ll save = 0, had = 0;
	while(l <= r){
		ll req = max(0LL, v[r].f - had);
		
		if (req > 0){
			ll b = min(req, v[l].s);
			v[l].s -= b;
			had += b;
			if (v[l].s == 0) l++;
		}

		else {
			save += v[r].s;
			had += v[r].s;
			v[r].s = 0;
			r--;
		}
	}
	cout << 1LL * 2 * tot - save << '\n';
	return 0;
}