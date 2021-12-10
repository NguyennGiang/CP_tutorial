#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int nxt[N], bg[N], dep[N], fa[N], k, id[N], sz[N], root[N];
vector <int> E[N], cr[N];
bool u[N], vr[N], nw[N];


int dfs(int x){
    u[x] = true;
    nw[x] = true;
    if (!u[nxt[x]]){
        int v = dfs(nxt[x]);
        if (v == -1){
            bg[x] = bg[nxt[x]];
            fa[x] = nxt[x];
            E[nxt[x]].push_back(x);
            nw[x] = false;
            return -1;
        }
        else {
            vr[x] = true;
            bg[x] = bg[nxt[x]];
            id[x] = sz[bg[x]];
            cr[bg[x]].push_back(x);
            sz[bg[x]]++;
            nw[x] = false;
            if (x == v) return -1;
            return v;
        }
    }
    else {
        if (nw[nxt[x]]){
            vr[x] = true;
            bg[x] = ++k;
            id[x] = sz[k];
            cr[k].push_back(x);
            sz[k]++;
            nw[x] = false;
            if (x == nxt[x]) return -1;
            return nxt[x];
        }
        else {
            bg[x] = bg[nxt[x]];
            fa[x] = nxt[x];
            E[nxt[x]].push_back(x);
            nw[x] = false;
            return -1;
        }
    }
    nw[x] = false;
}

void ddfs(int x, int d, int rt){
    root[x] = rt;
    dep[x] = d;
    for (int i = E[x].size() - 1; i >= 0; i--){
        int j = E[x][i];
        ddfs(j, d + 1, rt);
    }
}

int ff[N][20];

int lca(int x, int y){
    if (dep[x] > dep[y]) x^=y^=x^=y;
    for (int i = 19; i >= 0; i--) {
        if (dep[y] - dep[x] >= (1 << i)){
            y = ff[y][i];
        }
    }
    if (x == y) return x;
    for (int i = 19; i >= 0; i--){
        if (ff[x][i] != ff[y][i]){
            x = ff[x][i];
            y = ff[y][i];
        }
    }
    return fa[x];
}

int main(){
    int n, m;
    while (cin >> n){
        for (int i = 1; i <= n; i++) cin >> nxt[i];
        memset(u, 0, sizeof(u));
        memset(sz, 0, sizeof(sz));
        memset(vr, 0, sizeof(vr));
        memset(fa, 0, sizeof(fa));
        k = 0;
        for (int i = 1; i <= n; i++) if(!u[i]){
            dfs(i);
        }
        for (int i = 1; i <= n; i++) if (vr[i]){
            ddfs(i, 0, i);
        }

        for (int i = 1; i <= n; i++) ff[i][0] = fa[i];
        for (int h = 1; h < 20; h++){
            for (int i = 1; i <= n; i++){
                ff[i][h] = ff[ff[i][h-1]][h-1];
            }
        }
        cin >> m;
        while (m--){
            int x, y;
            cin >> x >> y;
            if (bg[x] != bg[y]){
                cout << -1 << '\n';
            }
            else {
                int ret;
                if (root[x] == root[y]){
                    int nd = lca(x, y);
                    ret = dep[x] + dep[y] - 2 * dep[nd];
                }
                else {
                    int nd1 = root[x], nd2 = root[y];
                    ret = dep[x] + dep[y] + min(abs(id[nd1] - id[nd2]),
                    sz[bg[nd1]] - max(id[nd1], id[nd2]) + min(id[nd1], id[nd2]));
                }
                cout << ret << '\n';
            }
        } 
        for (int i = 1; i <= n; i++) E[i].clear(), cr[i].clear();
    }
    return 0;
}