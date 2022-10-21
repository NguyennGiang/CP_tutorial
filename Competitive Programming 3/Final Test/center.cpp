#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define mod 1000000007
#define oo 1000000000

const int N = 1e5 + 5;
int n, q;
vector<int> g[N];
int dep[N];
int parent[N][20];
int ans;

void dfs(int u, int p){
	parent[u][0] = p;
	for (int v : g[u]){
		if (v == p) continue;
		dep[v] = dep[u] + 1;
		dfs(v, u);
	}
}

void preprocess(){
	dep[0] = 1;
	dfs(0, 0);

	for (int k = 1; k <= 18; k++){
		for (int i = 0; i < n; i++){
			parent[i][k] = parent[parent[i][k-1]][k-1];
		}
	}
}

int lca(int u, int v){
	if (dep[u] > dep[v]) swap(u, v);
	for (int k = 18; k >= 0; k--){
		if (dep[parent[v][k]] >= dep[u]){
			v = parent[v][k];
		}
	}

	for (int k = 18; k >= 0; k--){
		if (parent[u][k] != parent[v][k]){
			u = parent[u][k];
			v = parent[v][k];
		}
	}
	return parent[u][0];
}

void process(int a, int b, int c){
	int ac = lca(a, c);
	int ab = lca(a, b);
	int bc = lca(b, c);

	if (ab == bc){
		if (ac == b){
			ans = max(ans, 1);
		}
		else {
			if (ac != ab){
				int tmp = abs(dep[ab] - dep[b]) + abs(dep[ab] - dep[ac]) + 1;
				ans = max(ans, tmp);
			}
			else {
				ans = max(ans, 1 + abs(dep[ac] - dep[b]));
			}
		}
	}
	else {
		ans = max(ans, 1 + abs(dep[b] - max(dep[ab], dep[bc])));
	}
}

void solve(){
	cin >> n >> q;
	for (int i = 1; i < n; i++){
		int x; cin >> x;
		x--;
		g[i].push_back(x);
		g[x].push_back(i);
	}
	preprocess();

	while(q--){
		int a, b, c;
		cin >> a >> b >> c;
		a--,b--,c--;

		ans = 0;
		process(a, b, c);
		process(b, a, c);
		process(a, c, b);
		cout << ans << endl;
	}
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

