#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <queue>
#define RASENGAN ios_base::sync_with_stdio(0); cin.tie(0);
#define fi first
#define se second
using namespace std;

typedef pair <int, int> pii;
int n, m, s, t;
vector <vector <pii>> adj;
vector <bool> vis;

bool bfs(int mid){
	vis.assign(n + 1, false);
	queue <int> pq;
	pq.push(s);
	vis[s] = true;

	while(!pq.empty()){
		int u = pq.front();
		pq.pop();

		for (int i = 0; i < adj[u].size(); i++){
			int v = adj[u][i].fi;
			int w = adj[u][i].se;
			if (w >= mid && !vis[v]){
				vis[v] = true;
				pq.push(v);
			}
			else {
				continue;
			}
		}
	}
	if (vis[t]) return true;
	else return false;
}

int main(){
	RASENGAN

	cin >> n >> m >> s >> t;

	adj.assign(n + 1, vector <pii>());

	for (int i = 0; i < m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}

	int l = 1;
	int r = 1e5;
	int res = -1;
	while (l <= r){
		int m = l + (r - l) / 2;

		if(bfs(m)){
			res = m;
			l = m + 1;
		}
		else {
			r = m - 1;
		}
	}
	cout << r;
	return 0;

}