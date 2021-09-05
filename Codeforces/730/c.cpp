#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
#include <math.h>
#include <cstring>
#include <string.h>
#include <bits/stdc++.h>
#define RASENGAN ios_base::sync_with_stdio(0); cin.tie(0);
#define f first
#define s second
#define ll long long
#define ld long double

using namespace std;

typedef pair <int, int> pii;
const ll mod = 1e9 + 7;
const ll INF = 1e15;
const ld esp = 1e-9;

ld run(ld c, ld m, ld p, ld v){
	ld ans = 1;

	if (c > esp){
		ld tmp = min(c, v);
		ld nc = c - tmp;
		ld nm = m + tmp / 2.0;
		ld np = p + tmp / 2.0;
		if (m < esp){
			nm = m;
			np = p + tmp;
		}
		ans += c * run(nc, nm, np, v);
	}

	if (m > esp){
		ld tmp = min(m, v);
		ld nc = c + tmp / 2.0;
		ld nm = m - tmp;
		ld np = p + tmp / 2.0;
		if (c < esp){
			nc = c;
			np = p + tmp;
		}
		ans += m * run(nc, nm, np, v);
	}
	return ans;
}

void solve(){
	ld c, m, p, v;
	cin >> c >> m >> p >> v;
	
	ld ans = run(c, m , p , v);	
	cout << setprecision(12)<< fixed << ans << '\n';
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