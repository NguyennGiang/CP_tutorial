#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct Edge{
  int u, v;
  ll cap, cost;
  Edge(int u, int v, ll cap, ll cost) : u(u), v(v), cap(cap), cost(cost) {}

};

const ll INF = 1e18;
const int N = 3000;
vector<Edge> edges;
int n, k;
vector<int> g[N];
int pre[N];
long long dist[N];
int source, sink;

void add(int u, int v, ll cap, ll cost){
  g[u].push_back(edges.size());
  edges.push_back({u, v, cap, cost});
  g[v].push_back(edges.size());
  edges.push_back({v, u, 0, -cost});
}

bool spfa(int s, int f){
  fill(dist, dist + n + 3, INF);
  vector<bool> inQueue(n + 3, false);
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

long long mcmf(int s, int f){
  ll mincost = 0, maxflow = 0;
  int cnt = 0;
  while(spfa(s, f)){
    ll flow = INF;
    int cur = f, id;
    while(cur != s){
      id = pre[cur];
      flow = min(flow, edges[id].cap);
      cur = edges[id].u;
    }
    maxflow += flow;
    mincost += 1ll * flow * dist[f];
    cur = f;
    //cout << endl << endl<< flow  << " : " << dist[f] << endl;
    while(cur != s){
      //cout << cur << endl;
      id = pre[cur];
      edges[id].cap -= flow;
      edges[id ^ 1].cap += flow;
      cur = edges[id].u;    
    } 
    cnt++;
  }
  return mincost;
}

int main(){
  cin >> n >> k;
  source = 0;
  sink = n + 1;
  
  /* 
  source = 0
  sink = n + 1;
  */
  for (int i = 1; i <= n; i++){
    long long x; cin >> x;
    add(source, i, 1, x);
  }
  
  for (int i = 1; i <= n; i++){
    long long x; cin >> x;
    add(i, sink, 1, x);
  }
  
  for (int i = 1; i <= n - 1; i++){
    add(i, i + 1, k, 0);
  }
  int sink2 = n + 2;
  add(sink, sink2, k, 0);
  cout << mcmf(source, sink2);
}
