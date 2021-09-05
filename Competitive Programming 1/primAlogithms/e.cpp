
#include <iostream>
#include <queue>
#include <functional>
#include <algorithm>
#include <vector>
#define fi first
#define se second
using namespace std;

const int INF = 1e9;

typedef pair <int, int> pii;

vector <int> dist;
vector <bool> vis;
vector <vector <pii>> adj;
int n, m;

bool prim(){
	dist.assign(n + 1, INF);
	vis.assign(n + 1, false);

	priority_queue <pii, vector <pii>, greater <pii>> pq;
	pq.push({0, 1});
	dist[1] = 0;
	int cnt = 0;
	while(!pq.empty()){
		pii tmp = pq.top();
		pq.pop();

		int u = tmp.se;
		if (vis[u] == 1) continue;

		vis[u] = 1;
		cnt++;

		for (int i = 0; i < adj[u].size(); i++){
			int v = adj[u][i].fi;
			int w = adj[u][i].se;

			if (dist[v] > w && vis[v] == 0){
				dist[v] = w;
				pq.push({w, v});
			}
		}
	}

	return cnt == n;
}

int main(){
	cin >> n >> m;
	adj.assign(n + 1, vector <pii> ());

	while(m--){
		int x, y ,z;
		cin >> x >> y >> z;
		adj[x].push_back({y, z});
		adj[y].push_back({x, z});

		if (!prim()){
			cout << "-1\n";
			continue;
		}

		int mst = 0;
		for (int i = 1; i <= n; i++){
			mst += dist[i];
		}

		cout << mst << '\n';
		continue;
	}

	return 0;
}