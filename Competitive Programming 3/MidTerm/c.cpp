#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
vector<int> g[N];
int par[N][20], dep[N];

int lca(int a, int b){
    for (int l = 19; l >= 0; l--){
        if (dep[a] - (1 << l) >= dep[b]){
            a = par[a][l];
        }
    }
    for (int l = 19; l >= 0; l--){
        if (dep[b] - (1 << l) >= dep[a]){
            b = par[b][l];
        }
    }
    if (a == b) return a;

    for (int l = 19; l >= 0; l--){
        if (par[a][l] == par[b][l]){
            continue;
        }
        a = par[a][l];
        b = par[b][l];
    }
    return par[a][0];
}

void dfs(int u, int pa){
    for (int v : g[u]){
        if (v != pa){
            par[v][0] = u;
            dep[v] = dep[u] + 1;
            dfs(v, u);
        }
    }
}

int dist(int a, int b){
    return dep[a] + dep[b] - 2 * dep[lca(a, b)];
}

bool check(int d, int k){
    return (d <= k) && ((k - d) % 2 == 0);
}

int main(){
    int n;
    cin >> n;
    for (int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, 0);

    for (int l = 1; l < 20; l ++){
        for (int i = 1; i <= n; i++){
            par[i][l] = par[par[i][l-1]][l-1];
        }
    }
    int q;
    cin >> q;
    while (q--){
        int x, y, a, b, k;
        cin >> x >> y >> a >> b >> k;
        int d1 = dist(a, b);
        int d2 = dist(a, x) + dist(y, b) + 1;
        int d3 = dist(a, y) + dist(x, b) + 1;

        if (check(d1, k) || check(d2, k) || check(d3, k)){
            cout << "YES\n";
        }
        else cout << "NO\n";
    }
    return 0;
}