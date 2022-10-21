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
int n;
vector<int> g[N];
int pre[N];
int dist[N];
string t;
int cnt[27];
int source, sink;

void add(int u, int v, int cap, int cost){
  g[u].push_back(edges.size());
  edges.push_back({u, v, cap, cost});
  g[v].push_back(edges.size());
  edges.push_back({v, u, 0, -cost});
}

bool spfa(int s, int f){
  fill(dist, dist + n + 1, INF);
  vector<bool> inQueue(n + 1, false);
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
    while(cur != s){
      id = pre[cur];
      edges[id].cap -= flow;
      edges[id ^ 1].cap += flow;
      cur = edges[id].u;
    }
  }
  if (maxflow == int(t.size())) return mincost;
  return -1;
}

int main(){
  cin >> t;
  for (int i = 0; i < t.size(); i++){
    cnt[t[i] - 'a' + 1] ++;
  }
  source = 0;
  /*
  source: 0
  lớp 1: 1 -> m
  Lớp 2: m + 1 -> m + 26
  Lớp 3: m + 27 -> m + 52
  sink = mn + 53
  */
  int m; cin >> m;
  for (int i = 1; i <= m; i++){
    string s;
    cin >> s;
    int si; cin >> si;
    add(source, i, si, i);
    vector<int> v(27, 0);
    for (int j = 0; j < s.size(); j++){
      v[s[j] - 'a' + 1] ++;
    }
    for (int j = 1; j <= 26; j++){
      add(i, m + j, v[j], 0);
    }
  }

  for (int i = 1; i <= 26; i++){
    add(m + i, m + 26 + i, INF, 0);
  }

  sink = m + 53;
  for (int i = 1; i <= 26; i++){
    add(m + 26 + i, sink, cnt[i], 0);
  }

  n = m + 54;
  int cost = mcmf(source, sink);
  cout << cost;
}



