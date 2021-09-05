#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int, int>

using namespace std; 

const int INF = 1e9;
vector <vector <pii>> adj;
vector <int> path;
int n, m; 

bool BFs(int s, int mid, int dist[][2]){
	queue <pii> pq; 

	pq.push({s, 0});
	dist[s][0] = 1;

	while(pq.size() > 0){
		pii tmp = pq.front();
		pq.pop();
		int oce = tmp.se; 
		int u = tmp.fi;
		for (int i = 0; i < adj[u].size(); i++){
      int v = adj[u][i].se;
      int w = adj[u][i].fi;
      if (oce == 0){ // chưa có cạnh nào từ s -> u mà > mid
        if (w > mid && dist[v][1] == 0){
          dist[v][1] = 1;
          pq.push({v, 1});
        }
        if (w <= mid && dist[v][0] == 0){
          dist[v][0] = 1;
          pq.push({v, 0});
        }
      }
      else {
        if (w > mid){
          continue;
        }
        else if (dist[v][1] == 0) {
          dist[v][1] = 1; 
          pq.push({v, 1});
        }
      }
		}
	}
  if(dist[n][0] || dist[n][1])
    return true;
  else return false;
}

int main(){
	
	cin >> n >> m; 

	adj.assign(n + 1, vector <pii> ());
	int dist[n+1][2];
	
	for (int i = 0; i < m; i++){
		int a, b ,c; 
		cin >> a >> b >> c; 
		adj[a].push_back({c, b});
		adj[b].push_back({c, a});
	}

	int l = 0; 
	int r = INF; 
	while(l < r){
    	memset(dist, 0, sizeof(dist));
		int mid = l + (r - l) / 2;
		if (BFs(1, mid, dist)) r = mid;
		else l = mid + 1;
	}
  
 	memset(dist, 0, sizeof(dist));
 	if(!BFs(1, l, dist)){
 		cout << -1; 
 	}
 	else cout << l;
  return 0;

}