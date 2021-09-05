/*
	@Meaning of the question
		-A country where are N cities, M roads, K train routes, railway from 1 with access to all the city
		- Can remove up to now ask several railway, making the shortest distance to reach the No. 1 o'clock every point unchanged.
	@ Answer
		- First, using Dijkstra shortest path arrival is determined for each point, and obtaining the shortest end of each.
		- Next we through each rail, if the point is greater than the shortest path to reach undoubtedly deleted directly.
		- if equal to a shortest distance point and the point of penetration is greater than 1, indicating that multiple lines can be reached at the same distance, may be omitted.
		- Taking into account the rail and road can sit at the same time, and the title has multiple edges.

*/

#include <bits/stdc++.h>
#define maxn 1000005
#define INF 1e15
#define fi first
#define se second
#define ll long long
#define pii pair <int ,int>
#define pll pair <ll, ll>
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;

int n, m, k;
vector <ll> dist;  // sum of weight;
vector <vector<pll>> adj; 
vector <pll> trains;
ll deg[maxn]; // numbers of the path from 1 to u;

void Dijkstra(int s){
	
	dist[s] = 0; 
	priority_queue <pll, vector <pll>, greater<pll> > pq;
	pq.push({0, s});
	while(!pq.empty()){
		pll tmp = pq.top();
		pq.pop(); 
		int u = tmp.se;
		if (tmp.fi != dist[u]){
			continue;
		}
		for (int i = 0; i < adj[u].size(); i++){
			
			ll w = adj[u][i].fi;
			int v = adj[u][i].se;
			
			if(dist[v] == dist[u] + w){
				deg[v]++;
			}
			if (dist[v] > dist[u] + w){
				dist[v] = dist[u] + w; 
				pq.push(make_pair(dist[v], v));
				deg[v] = 1; 
			}
		}
	}
}

int main(){
	fast_io
	cin >> n >> m >> k;
	adj.assign(n+1, vector<pll>());
	dist.assign(n+1, INF);

	for (int i = 0; i < m; i++){
		int u, v;
		ll w; 
		cin >> u >> v >> w;
		adj[u].push_back({w,v});
		adj[v].push_back({w,u});
	}
	

	for (int i = 0; i < k ; i++){
		int to; 
		ll w; 
		cin >> to >> w; 
		trains.push_back({w,to});
		adj[1].push_back({w,to});
	}

	Dijkstra(1);
	
	//for (int i = 1; i <= n; i++) cout << dist[i] << " ";
	//cout << endl;
	//for (int i = 1; i <= n; i++) cout << deg[i] << " ";
	int res = 0; 
	
	for (int i = 0; i < trains.size(); i++){
		ll v = trains[i].se;
		ll w = trains[i].fi;
		if (dist[v] < w){
			res++;
		}
		else if (dist[v] == w && deg[v] > 1){
			res++; 
			deg[v]--;
		}
	}
	cout << res << '\n'; 
	return 0;
}