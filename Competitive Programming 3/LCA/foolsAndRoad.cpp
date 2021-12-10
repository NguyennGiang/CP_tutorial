#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, q, a[N], g[N], ans[N];
map<pair<int, int>, int> idedge;
vector <int> e[N];
int f[N][20], dep[N];

void dfs1(int u, int fa){
    f[u][0] = fa;
    dep[u] = dep[fa] + 1;
    for (int i = 1; i < 19; i++){
        f[u][i] = f[f[u][i-1]][i-1];
    }
    for (int v : e[u]){
        if (v != fa) dfs1(v, u);
    }
}

int lca(int x, int y){
     if (dep[x] < dep[y]) swap(x, y);
     for (int i = 18; i >= 0; i--){
        if (dep[f[x][i]] >= dep[y]){
            x = f[x][i];
        }
     }
     if (x == y) return x;

     for (int i = 18; i >= 0; i--){
        if (f[x][i] != f[y][i]){
            x = f[x][i], y = f[y][i];
        }
     }
     return f[x][0];
}

void dfs2(int u, int fa){
    g[u] = a[u];
    for (int v : e[u]){
        if (v != fa){
            dfs2(v, u);
            g[u] += g[v];
        }
    }
    ans[idedge[{u, f[u][0]}]] = g[u];
}

int main(){
    cin >> n;

    for (int i = 1, x, y; i < n; i++){
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
        idedge[{x, y}] = idedge[{y, x}] = i;
    }
    dfs1(1, 0);
    cin >> q;
    while(q--){
        int u, v, Lca;
        cin >> u >> v;
        Lca = lca(u, v);
        //cerr << u << " " << v << " " << Lca << endl;
        a[u]++;
        a[v]++;
        a[Lca] -= 2;
    }
    dfs2(1, 0);
    for (int i = 1; i < n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}