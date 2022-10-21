#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct Edge{
  int u, v;
  ll cap, cost;
  Edge(int u, int v, int cap, int cost) : u(u), v(v), cap(cap), cost(cost) {}

};

const int INF = 1e9;
const int N = 1000;
vector<Edge> edges;
int n, q;
vector<int> g[N];
int pre[N];
int dist[N];
int source, sink;

void add(int u, int v, int cap, int cost){
  g[u].push_back(edges.size());
  edges.push_back({u, v, cap, cost});
  g[v].push_back(edges.size());
  edges.push_back({v, u, 0, -cost});
}

bool spfa(int s, int f){
  fill(dist, dist + 2 * n + 3, INF);
  vector<bool> inQueue(2 * n + 3, false);
  queue<int> q;
  q.push(s);
  inQueue[s] = true;
  dist[s] = 0;
  while(q.size()){
    int u = q.front();
    inQueue[u] = false;
    q.pop();
    for (int id : g[u]){
      int v = edges[id].v;
      ll cap = edges[id].cap, cost = edges[id].cost;
      if (cap <= 0 || dist[v] <= dist[u] + cost){
        continue;
      }

      dist[v] = dist[u] + cost;
      pre[v] = id;
      if (inQueue[v] == false){
        q.push(v);
        inQueue[v] = true;
      }
    }
  }
  return dist[f] != INF;
}

int mcmf(int s, int f){
  ll mincost = 0, maxflow = 0;
  while(spfa(s, f)){
    ll flow = INF;
    int cur = f, id;
    while(cur != s){
      id = pre[cur];
      flow = min(flow, edges[id].cap);
      cur = edges[id].u;
    }
    maxflow += flow;
    // cout << dist[f] << endl;
    // cout << flow << endl;
    mincost += flow * dist[f];
    cur = f;
    //cout << endl << endl<< flow  << " : " << dist[f] << endl;
    while(cur != s){
      //cout << cur << endl;
      id = pre[cur];
      edges[id].cap -= flow;
      edges[id ^ 1].cap += flow;
      cur = edges[id].u;
    }
  }
  if (maxflow == n) return mincost;
  return -1;
}

int main(){
  cin >> n >> q;
  source = 0;
  /*
  source = 0
  lop 1 : 1 -> n;
  lớp 2: n + 1 -> 2n;
  sink 2n + 1;
  */
  vector<int> l(n + 1, 1);
  vector<int> r(n + 1, n);

  for (int i = 0; i < q; i++){
    int op, u, v, c;
    cin >> op >> u >> v >> c;
    // for i = u -> v:
    if (op == 1){
      for (int j = u; j <= v; j++){
        l[j] = max(l[j], c);
      }
    }
    else {
      for (int j = u; j <= v; j++){
        r[j] = min(r[j], c);
      }
    }
  }

  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= n; j++)
      add(source, i, 1, 2 * j - 1);
  }

  for (int i = 1; i <= n; i++){ //  lop 2
    for (int j = l[i]; j <= r[i]; j++){ // lop 1
      //cout << i << ' ' << j << endl;
      add(j, i + n, 1, 0);
    }
    //cout << endl;
  }

  sink = 2 * n + 1;
  for (int i = 1; i <= n; i++){
    add(n + i, sink, 1, 0);
  }
  cout << mcmf(source, sink);
}

