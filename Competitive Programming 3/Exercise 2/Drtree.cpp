#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, q;
int root = 1;
int w[N], depth[N], par[N][20];
long long sum[N];
vector <int> g[N];

void dfs(int u, int p){
    sum[u] = w[u];
    for (int v : g[u]){
        if (v == p) continue;
        depth[v] = depth[u] + 1;
        dfs(v, u);
        sum[u] += sum[v];
    }
}

int getLca(int a, int b){
    if (depth[a] < depth[b]) swap(a, b);
    for (int i = 18; i >= 0; i--){
        if (depth[a] - (1 << i) >= depth[b]){
            a = par[a][i];
        }
    }
    if (a == b) return a;
    for (int i = 18; i >= 0; i--){
        if (par[a][i] != 0 && par[a][i] != par[b][i]){
            a = par[a][i];
            b = par[b][i];
        }
    }
    return par[a][0];
}

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> w[i];
    }
    for (int i = 2; i <= n; i++){
        cin >> par[i][0];
        g[par[i][0]].push_back(i);
    }
    for (int i = 0; i < 18; i++){
        for (int j = 1; j <= n; j++){
            if (par[j][i-1])
                par[j][i] = par[par[j][i-1]][i-1];
        }
    }
    dfs(1, -1);
    // for (int i = 1; i <= n; i++) cout << sum[i] << " ";
    // cout << endl;
    cin >> q;
    while (q--){
        char op;
        int x;
        cin >> op >> x;
        if (op == 'R'){
            root = x;
        }
        else {
            if (root == x){
                cout << sum[1] << endl;
                continue;
            }

            int lca = getLca(root, x);
            if (lca == x){
                int dep = depth[root] - depth[x] - 1;
                x = root;
                for (int i = 18; i >= 0; i--){
                    if (dep >= (1 << i)){
                        x = par[x][i];
                        dep -= (1 << i);
                    }
                }
                cout << sum[1] - sum[x] << endl;
            }
            else cout << sum[x] << endl;
        }
    }
    return 0;
}