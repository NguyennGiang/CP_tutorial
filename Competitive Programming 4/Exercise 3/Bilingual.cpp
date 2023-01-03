/*
E: a b c d e
F: f g h i j

E: a b c i j
F: f g h d e
{i, j, d, e} --> answer = 4


E: a b c i j
E: f g h d e
{f, g, h, i, j} --> answer = 5

EE --> số lượng từ bilingual a1
EF --> a2
FF --> a3
FE --> a4

--> answer = min(a1, a2, a3, a4)



source = c1 , sink = c2 

c1 - a - c2
c1 - b
c - c2

n câu -> w từ (mỗi từ là E, F)

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct Edge{
  int u, v;
  ll cap, flow;
  Edge(int u, int v, ll cap) : u(u), v(v), cap(cap), flow(0) {}

};

const ll INF = 1e9;
const int N = 10000;
// N = 200 câu + 4000 từ + 5000
const int UP = 5000;
vector<Edge> edges;
int n, k;
vector<int> g[N];
int level[N];
int iter[N];
int source, sink;
map<string, int> m;

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
  // n đỉnh đại diện cho n câu
  // n + 1 
  int t; cin >> t;
  for (int tc = 1; tc <= t; tc++){
    source = 1;
    sink = 2;
    
    // Flow thông thường sẽ tính theo cạnh
    // Bài toán này cần là liên quan tới các word -> đỉnh
    // Câu u, từ v
    // từ ảo của v' = v + UP
    // u -> v: cap = INF
    // v -> v': cap = 1
    // v' -> u: cap = INF
    
    int n; cin >> n;
    string s; getchar();
    int id = n + 1;
    for (int i = 0; i < n; i++){
      getline(cin, s);
      // cout << s << endl << endl;
      istringstream ss(s);
      string word;
      while(ss >> word){
        /*
        Nếu word chưa xuất hiện:
        - Gán id cho nó
        - Nối từ id -> id + UP
        Nếu đã xuất hiện:
        - Không phải gán hay nối id -> id + UP
        Vẫn phải nối giữa từ và câu
        */
        if (m[word]) {
          add(i + 1, m[word], INF);
          add(m[word] + UP, i + 1, INF);
          //cout << i +1 <<' '<<m[word] <<' '<<INF << endl;
          //cout << m[word] + UP <<' '<<i + 1 <<' '<<INF << endl;
          continue;
        }
        m[word] = id++;
        add(i + 1, m[word], INF);
        add(m[word] + UP, i + 1, INF);
        add(m[word], m[word] + UP, 1);
        
          //cout << i +1 <<' '<<m[word] <<' '<<INF << endl;
          //cout << m[word] + UP <<' '<<i + 1 <<' '<<INF << endl;
          //cout << m[word] <<' '<<m[word] + UP <<' ' << 1 << endl;
      }
      
    }
    
    cout << "Case #" << tc << ": " << flow(source, sink) << endl;
    
    edges.clear();
    for (int i = 0; i < N; i++){
      g[i].clear();
    }
    m.clear();
  }
}
