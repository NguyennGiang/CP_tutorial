/*
  u -> v;
  c[u][u'] = w; -> kiểm tra được là có cạnh nối từ u -> u'?
  u' = u + n
  => tổng sẽ có 2n node => tìm luồng cực đại cho 2n node;
  g[u_in].push_back(u_out)
  u_in -> u_out -> v_in -> v_out
  50 * 1000^2 * T
*/


#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int N = 105;
const int M = 1050;
const int INF = 1e9;
int n, m;

struct Edge {
  int u, v, cap, flow;
  Edge(int u = 0, int v = 0, int cap = 0, int flow = 0)
    : u(u), v(v), cap(cap), flow(flow) {}
};

vector<Edge> edges;
vector<int> g[N];
int level[N];
int iter[N];

int bfs(int s = 1, int t = n){
  queue<int> q;
  q.push(s);
  memset(level, -1, sizeof(level));
  level[s] = 0;
  while(q.size()){
    int u = q.front();
    q.pop();
    for (int i : g[u]){
      if (level[edges[i].v] != -1) continue;
      if (edges[i].cap <= edges[i].flow) continue;
      level[edges[i].v] = level[edges[i].u] + 1;
      q.push(edges[i].v);
    }
  }
  return level[t] != -1;
}

int dfs(int s, int t, int p){
  if (p == 0) return 0;
  if (s == t) return p;
  for (int &i = iter[s]; i < g[s].size(); i++){
    int id = g[s][i];
    int v = edges[id].v;
    
    if (level[v] != level[s] + 1) continue;
    if (edges[id].cap <= edges[id].flow) continue;
    int f = min(p, edges[id].cap - edges[id].flow);
    f = dfs(v, t, f);
    if (f == 0) continue;
    edges[id].flow += f;
    edges[id^1].flow -= f;
    return f;
  }
  return 0;
}

int maxflow(int s = 1, int t = n){
  int flow = 0, tmp;
  while(bfs(s, t)){
    memset(iter, 0, sizeof(iter));
    while(tmp = dfs(s, t , INF)){
      flow += tmp;
    }
  }
  return flow;
}

void addEdge(int u, int v, int cap){
  g[u].push_back(edges.size());
  edges.push_back({u, v, cap});
  g[v].push_back(edges.size());
  edges.push_back({v, u, 0});
}

int main(){
  while(cin >> n >> m && m && n){
    addEdge(1, n+1, INF);
    //addEdge(n, 2*n, INF);
    for (int i = 2; i < n; i++){
      int a, b;
      cin >> a >> b;
      addEdge(a, a + n, b);
    }
    
    for (int i = 0; i < m; i++){
      int a, b, c;
      cin >> a >> b >> c;
      addEdge(a + n, b, c);
      addEdge(b + n, a, c);
    }
    cout << maxflow() << endl;
    for (int i = 0; i <= 2*n + 1; i++){
      g[i].clear();
      edges.clear();
    }
  }
}
