#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct Edge{
  int u, v;
  ll cap, flow;
  Edge(int u, int v, ll cap) : u(u), v(v), cap(cap), flow(0) {}

};

const ll INF = 1e18;
const int N = 150;
vector<Edge> edges;
int n, k;
vector<int> g[N];
int level[N];
int iter[N];
int source, sink;

void add(int u, int v, ll cap){
  g[u].push_back(edges.size());
  edges.push_back({u, v, cap});
  g[v].push_back(edges.size());
  edges.push_back({v, u, 0});
}

bool bfs(int s, int f){
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
      level[edges[i].v] = level[u] + 1;
      q.push(edges[i].v);
    }
  }
  return level[f] != -1;
}


int dfs(int s, int t, ll flow){
  if (flow == 0) return 0;
  if (s == t) return flow;
  for (int &i = iter[s]; i < g[s].size(); i++){
    int id = g[s][i];
    int v = edges[id].v;
    
    if (level[v] != level[s] + 1) continue;
    if (edges[id].cap <= edges[id].flow) continue;
    
    int f = min(flow, edges[id].cap - edges[id].flow);
    f = dfs(v, t, f);
    if (f == 0) continue;
    edges[id].flow += f;
    edges[id^1].flow -= f;
    return f;
  }
  return 0;
}

long long flow(int s, int f){
  int newFlow, sumFlow = 0;
  
  while(bfs(s, f)){
    memset(iter, 0, sizeof(iter));
    while(newFlow = dfs(s, f, INF)){
      sumFlow += newFlow;
    }
  }
  
  return sumFlow;
}

int main(){
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t;
  for (int tc = 1; tc <= t; tc++){
    cin >> n;
    cin >> source >> sink;
    int c; cin >> c;
    while(c--){
      int u, v, w;
      cin >> u >> v >> w;
      add(u, v, w);
      add(v, u, w);
    }
    
    cout << "Case " << tc << ": " << flow(source, sink) << endl;
    
    edges.clear();
    for (int i = 0; i <= n; i++){
      g[i].clear();
    }
  }
}

