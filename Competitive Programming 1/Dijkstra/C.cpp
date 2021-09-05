#include <bits/stdc++.h>
#define maxn 500001
#define INF 1001001001
#define fi first
#define se second
#define pii pair <int ,int>

using namespace std; 

vector <int> G[maxn], W[maxn];
int n; 
int dist[maxn];

void Dijkstra(int s){

	int r = 0, u, v, c, w;
	priority_queue <pii,vector <pii>, greater<> > pq;
	for (int i = 0; i < n; i++){
		dist[i] = INF;
	}

	dist[s] = 0;
	pq.push({0, s});
	while(pq.size() > 0){
		pii tmp = pq.top();
		pq.pop();
		w = tmp.fi;
		u = tmp.se; 
		if (w > dist[u]) continue;
		for (int i = 0; i < G[u].size(); i++){
			v = G[u][i];
			w = W[u][i];
			if (dist[u] + w < dist[v]){
				 dist[v] = dist[u] + w; 
				 pq.push({dist[v], v});
			}
		}
	}
}

int main(){
	int m, q; 
	int u, v, w; 
	scanf("%d %d %d", &n, &m, &q);
	while(m--){
		scanf("%d %d %d", &u, &v, &w);
		G[u].push_back(v);
		G[v].push_back(u);
		W[u].push_back(w);
		W[v].push_back(w);
	}
	while(q--){
		scanf("%d", &u);
		Dijkstra(u);
		int ma = 0, count = 0; 
		for (int i = 0; i < n; i++){
			if(dist[i] != INF){
				if (ma < dist[i]){
					ma = dist[i];
					count = 1;
				}
				else if (ma == dist[i]){
					count++;
				}
		
			}	
		}
		printf("%d %d\n", ma, count);	
	}
	return 0;

}