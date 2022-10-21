#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, long long>;

const int N = 501;
const long long INF = 1e18;
long long n, m, p[N], cap[N][N];
bool vis[N];
vector<int> g[N];

long long bfs(int s = 1, int t = n){
    fill(p + 1, p + n + 1, -1);
    p[s] = -2;

    queue<pii> q;
    q.push({s, INF});
    while(!q.empty()){
        int u = q.front().first;
        long long f = q.front().second;
        q.pop();

        for (int v : g[u]){
            if (p[v] == -1 && cap[u][v]){
                p[v] = u;
                long long tmp = min(f, cap[u][v]);
                if (v == t) return tmp;
                q.push({v, tmp});
            }
        }
    }
    return 0;
}

long long maxflow(int s = 1, int t = n){
    long long flow = 0;
    long long tmp = 0;
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

int main(){
    cin >> n >> m;
    for (int i = 0, a, b; i < m; i++){
        long long c;
        cin >> a >> b >> c;
        g[a].push_back(b);
        g[b].push_back(a);
        cap[a][b] += c;
    }
    cout << maxflow() << endl;

    return 0;
} 