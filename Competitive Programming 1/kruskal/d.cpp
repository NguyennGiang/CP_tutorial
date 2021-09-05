#include <iostream>
#include <vector>
#define ll long long
#define RASENGAN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const int INF = 20005;

int n, m;
int par[INF];

int findSet(int u){
	while(u != par[u]){
		u = par[u];
	}
	return u;
}

void solve(int tc){
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		int x;
		cin >> x;
		if (x == 0){
			par[i] = i;
		}
		else {
			par[i] = x;
		}
	}

	cout << "Case #" << tc << ":\n";

	while(m--){
		char t;
		cin >> t;
		if (t == 'Q'){
			int u, v;
			cin >> u >> v;
			u = findSet(u);
			v = findSet(v);
			cout << (u == v ? "YES\n" : "NO\n");
		}
		else {
			int u;
			cin >> u;
			par[u] = u;
		}
	}
}

int main()
{
	RASENGAN

	int t;
	cin >> t;
	for (int i = 1; i <= t; i++){
		solve(i);
	}
	return 0;
}