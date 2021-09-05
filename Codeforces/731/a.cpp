#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef pair <int, int> pii;

void solve(){
	pii a, b, g;
	cin >> a.f >> a.s;
	cin >> b.f >> b.s;
	cin >> g.f >> g.s;
	int res = 0;
	res += abs(a.f - b.f) + abs(a.s - b.s);
	if ((a.f == b.f && a.f == g.f && min(a.s, b.s) < g.s && max(a.s, b.s) > g.s) || (a.s == b.s && a.s == g.s && min(a.f, b.f) < g.f && max(a.f, b.f) > g.f)){
		res += 2;
	}
	cout << res << '\n';
}

int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}