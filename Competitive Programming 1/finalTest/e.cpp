#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <functional>
#define RASENGAN ios_base::sync_with_stdio(0); cin.tie(0);
#define fi first
#define se second

using namespace std;

typedef pair <int, int> pii;
const int maxn = 305;
int n;
vector <int> vis;
int we[maxn];
int a[maxn][maxn];
vector <int> dist;
vector <vector <pii>> adj;

int prim(){

	vis.assign(n + 1, false);
	dist.assign(n + 1, 1e9);

	priority_queue <pii, vector<pii>, greater<pii>> pq;
	pq.push({0, 0});
	dist[0] = 0;

	while(!pq.empty()){
		pii tmp = pq.top();
		pq.pop();

		int u = tmp.se;
		if (vis[u] == 1){
			continue;
		}

		vis[u] = 1;

		for (int i = 0; i < adj[u].size(); i++){
			int v = adj[u][i].fi;
			int w = adj[u][i].se;

			if(!vis[v] && dist[v] > w){
				dist[v] = w;
				pq.push({w, v});
			}
		}
	}

	int res = 0;

	for (int i = 1; i <= n; i++){
		res += dist[i];
	}
	return res;
}

int main(){
	cin >> n;

	for (int i = 1; i <= n; i++){
		cin >> we[i];
	}

	adj.assign(n + 1, vector <pii> ());
	dist.assign(n + 1, 0);

	for (int i = 1; i <= n; i++){
		adj[0].push_back({i, we[i]});
	}



	for (int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
			if (i != j){
				adj[i].push_back({j, a[i][j]});
			}
		}
	}
	cout << prim();
	return 0;
}