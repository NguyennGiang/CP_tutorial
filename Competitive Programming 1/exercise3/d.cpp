#include <bits/stdc++.h>
#define pii pair<int, int>
#define piii pair <pair <int ,int>, int>
#define fi first
#define se second

using namespace std;

const int maxn = 1e9;
int n, m;
vector <vector<pii>> v;
vector <int> dist;

void Dijsktra(int s){

  dist.assign(n + 1, maxn);
  priority_queue <piii, vector <piii>, greater<piii>> q;
  /*
    minHeap q: 
      +q.fi.fi = numbers of gear-mode changes
      +q.fi.se = the current city
      +q.se = current status
  */
  q.push({{0, s}, 0});
  q.push({{0, s}, 1});
  dist[s] = 0;
  while(!q.empty()){
    piii tmp = q.top(); 
    q.pop();
    int u = tmp.fi.se;
    if (tmp.fi.fi != dist[u]) continue;
   
    
    for (int i = 0; i < v[u].size(); i++){
      int sta = v[u][i].se; 
      int adj = v[u][i].fi;
      if (sta == tmp.se && dist[adj] > dist[u]){
        q.push({{tmp.fi.fi, adj}, sta});
        dist[adj] = tmp.fi.fi;
      }
      else if (dist[adj] > dist[u] + 1 && sta != tmp.se){
        q.push({{tmp.fi.fi + 1, adj}, sta});
        dist[adj] = tmp.fi.fi + 1;
      }
    }
  }
}

int main(){
  cin >> n >> m;
  v.assign(n+1, vector<pii>());
  for (int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    v[a].push_back({b, 0}); // status : 0 - uphill / 1 - downhill
    v[b].push_back({a, 1}); 
  }
  int st, ed;
  cin >> st >> ed;
  Dijsktra(st);
  cout << dist[ed];
  return 0;
}