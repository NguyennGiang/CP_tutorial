#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int N = 501;
const int INF = 1e9;
int n, m, p[N], cap[N][N];
bool vis[N];
vector<int> g[N];

int bfs(int s = 1, int t = n){
    fill(p + 1, p + n + 1, -1);
    p[s] = -2;

    queue<pii> q;
    q.push({s, INF});
    while(!q.empty()){
        int u = q.front().first;
        int f = q.front().second;
        q.pop();

        for (int v : g[u]){
            if (p[v] == -1 && cap[u][v]){
                p[v] = u;
                int tmp = min(f, cap[u][v]);
                if (v == t) return tmp;
                q.push({v, tmp});
            }
        }
    }
    return 0;
}

int maxflow(int s = 1, int t = n){
    int flow = 0;
    int tmp = 0;
    while(tmp = bfs()){
        flow += tmp;
        int u = t;
        while(u != s){
            int v = p[u];
            cap[v][u] -= tmp;
            cap[u][v] += tmp;
            u = v;
        }
    }
    return flow;
}

void dfs(int u = 1){
    vis[u] = true;
    for (int v : g[u]){
        if (!vis[v] && cap[u][v]){
            dfs(v);
        }
    }
}

int main(){
    cin >> n >> m;
    for (int i = 0, a, b; i < m; i++){
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        cap[a][b]++;
        cap[b][a]++;
    }
    cout << maxflow() << endl;

    dfs();
    for (int u = 1; u <= n; u++){
        if (!vis[u]) continue;
        for (int v : g[u]){
            if (!vis[v]){
                cout << u << ' ' << v << endl;
            }
        }
    }
    return 0;
} 