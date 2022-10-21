#include<bits/stdc++.h>
using namespace std;
const int N = 1010;
const int INF = 0x3f3f3f3f;
int g[N][N];
int d[N];
int p[N];
int vis[N];
int n, m;
int s, t;

int spfa(int s, int t){
    queue<int> q;
    memset(vis, 0, sizeof(vis));

    for (int i = 1; i <= n; i++){
        d[i] = (i == s) ? 0 : INF;
    }

    q.push(s);

    while(!q.empty()){
        int u = q.front();
        q.pop();
        vis[u] = false;
        for (int v = 1; v <= n; v++){
            if (g[u][v]){
                if (d[v] > d[u] + g[u][v]){
                    d[v] = d[u] + g[u][v];
                    p[v] = u;
                    if (!vis[v]){
                        vis[v] = 1;
                        q.push(v);
                    }
                }
            }
        }
    }
    return d[t];
}

void change(int u){
    if (p[u] == -1) return;
    g[u][p[u]] = -g[u][p[u]];
    g[p[u]][u] = INF;
    change(p[u]);
}

int main(){
    while(cin >> n && n){
        memset(g, INF, sizeof(g));
        memset(p, -1, sizeof(p));
        cin >> m;
        while(m--){
            int a, b, c; 
            cin >> a >> b >> c;
            g[a][b] = g[b][a] = c;
        }

        int ans = spfa(1, n);
        change(n);
        ans += spfa(1, n);
        if (ans < INF){
            cout << ans << endl;
        }
        else cout << "Back to jail\n";
    }
    return 0;
}