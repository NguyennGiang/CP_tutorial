#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define mod 1000000007
#define oo 1000000000
typedef pair<int, int> pii;

const int N = 10000 + 5;
int n;
vector<pii> g[N];
int lev[N], par[N][20];
int dist[N];

void dfs(int u, int p){
	par[u][0] = p;
	for (pii tmp : g[u]){
		int v = tmp.fi;
		int w = tmp.se;
		if (v == p) continue;
		lev[v] = lev[u] + 1;
		dist[v] = dist[u] + w;
		dfs(v, u);
	}
}

int lca(int u, int v){
	if (lev[u] > lev[v]) swap(u, v);

	for (int k = 19; k >= 0; k--){
		if (lev[par[v][k]] >= lev[u]){
			v = par[v][k];
		}
	}

	for (int k = 19; k >= 0; k--){
		if (par[u][k] != par[v][k]){
			u = par[u][k];
			v = par[v][k];
		}
	}
	while(u != v){
		u = par[u][0];
		v = par[v][0];
	}
	return u;
}

int path(int u, int k){
	for (int i = 19; i >= 0 && u > 0; i--){
		if ((1 << i) <= k){
			u = par[u][i];
			k -= 1 << i;
		}
	}
	return u;
}

int kth(int u, int v, int k){
	int l = lca(u, v);
	int d = lev[u] - lev[l] + 1;
	if (d >= k){
		return path(u, k - 1);
	}
	else {
		int tmp = abs(lev[l] - lev[u]) + abs(lev[l] - lev[v]) + 1;
		k = tmp - k;
		return path(v, k);
	}
}

void solve(){
	cin >> n;
	for (int i = 1; i < n; i++){
		int a, b, c;
		cin >> a >> b >> c;
		g[a].push_back({b, c});
		g[b].push_back({a, c});
	}

	lev[1] = 0;
	dfs(1, 0);

	for (int j = 1; j < 20; j++){
		for (int i = 1; i <= n; i++){
			par[i][j] = par[par[i][j-1]][j-1];
		}
	}

	string s;
	while(cin >> s){
		if (s == "DONE"){
			break;
		}
		else if (s == "DIST"){
			int a, b;
			cin >> a >> b;
			int t = lca(a, b);

			cout << dist[a] + dist[b] - 2 * dist[t] << endl;
		}
		else {
			int a, b, c;
			cin >> a >> b >> c;
			cout << kth(a, b, c) << endl;
		}

	}
	memset(dist, 0, sizeof(dist));
	memset(lev, 0, sizeof(lev));
	memset(par, 0, sizeof(par));
	for (int i = 0; i <= n; i++){
		g[i].clear();
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}

