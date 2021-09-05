#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair <int, int>

using namespace std; 

vector <int> dist;
vector <vector<pii>> adj;
vector <int> path;
int n, m;

void Dijkstra(int s){
  dist.assign(n + 1, 1e9);
  path.assign(n + 1, -1);
  priority_queue <pii, vector<pii>, greater <pii> > pq;
  pq.push({0, s});
  dist[s] = 0;
  while(pq.size() > 0){
    pii x = pq.top();
    pq.pop();
    int u = x.se;
    if (x.fi != dist[u]) continue;
    for (int i = 0; i < adj[u].size(); i++){
      int v = adj[u][i].se;
      int w = adj[u][i].fi;
      if (dist[v] > dist[u] + w){
        dist[v] = dist[u] + w;
        path[v] = u;
        pq.push( {dist[v], v} );
      }
    }  
  }
}

void printPath(int s, int f){
  if (s == f) {
    cout << f << " ";
  }
  else{
    if (path[f] == -1){
      cout << -1 << endl;
    }
    else {
      printPath(s, path[f]);
      cout << f << " ";
    }
  }
}


int main() {
  cin >> n >> m;
  adj.assign(n + 1, vector<pii>());
  for (int i = 0; i < m ; i++){
    int a, b, c; 
    cin >> a >> b >> c; 
    adj[a].push_back(make_pair(c, b));
    adj[b].push_back(make_pair(c, a));
  }   
  Dijkstra(1);
  printPath(1, n);
  return 0;
}