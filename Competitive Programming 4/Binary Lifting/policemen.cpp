#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define mod 1000000007
#define oo 1000000000

const int N = 1e4 + 5;
int n, q;
vector<int> g[N];
int dep[N], p[N][20];

void dfs(int u, int par){
	dep[u] = dep[par] + 1;
	p[u][0] = par;
	for (int v : g[u]){
		if (v == par) continue;
		dfs(v, u);
	}
}

int lca(int u, int v){
	if (dep[u] > dep[v]) swap(u, v);

	for (int k = 18; k >= 0; k--){
		if (dep[p[v][k]] >= dep[u]){
			v = p[v][k];
		}
	}

	for (int k = 18; k >= 0; k--){
		if (p[u][k] != p[v][k]){
			u = p[u][k];
			v = p[v][k];
		}
	}

	while(u != v){
		u = p[u][0];
		v = p[v][0];
	}
	return u;
}

void solve(){
	cin >> n;
	for (int i = 1; i < n; i++){
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	//memset(p, -1, sizeof(p));
	dep[0] = -1;
	dfs(1, 0);


	for (int j = 1; j < 20; j++){
		for (int i = 1; i <= n; i++){
			if (p[i][j-1] != -1){
				p[i][j] = p[p[i][j-1]][j-1];
			}
		}
	}

	cin >> q;
	while(q--){
		int a, b;
		cin >> a >> b;
		if (dep[a] < dep[b]){
			cout << "NO\n";
		}
		else {
			cout << "YES" << " " << lca(a, b) << endl;
		}
	}
	return ;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}
	return 0;
}

