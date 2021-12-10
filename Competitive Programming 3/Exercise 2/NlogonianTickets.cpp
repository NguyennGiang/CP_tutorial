#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int maxLog = 18;
int H[N];
int st[N][maxLog];
int mx[N][maxLog];
struct Node {
    int v, w;
};
vector<Node> g[N];

void dfs(int x, int p, int h, int w){
    H[x] = h;
    st[x][0] = p == 0 ? x : p;
    mx[x][0] = w;
    for (int k = 1; k < maxLog; k++){
        st[x][k] = st[st[x][k-1]][k-1];
        mx[x][k] = max(mx[mx[x][k-1]][k-1], mx[x][k-1]);
    }
    for (Node node : g[x]){
        if (node.v == p) continue;
        dfs(node.v, x, h + 1, node.w);
    }
}

const int inf = 2e9;
pair<int, int> solve(int x, int l){
    pair<int, int> q = {x, -inf};
    for (int k = 0; k < maxLog; k++){
        if (l & (1 << k)){
            q.second = max(q.second, mx[q.first][k]);
            q.first = st[q.first][k];
        }
    }
    return q;
}

pair<int, int> lca(int x, int y){
    if (H[x] > H[y]) swap(x, y);
    pair<int, int> q = solve(y, H[y] - H[x]);
    y = q.first;
    int res = q.second;
    if (x == y) return q;
    for (int k = maxLog - 1; k >= 0; k--){
        if (st[x][k] != st[y][k]){
            res = max(res, mx[x][k]);
            res = max(res, mx[y][k]);
            x = st[x][k];
            y = st[y][k];
        }
    }
    res = max(res, mx[x][0]);
    res = max(res, mx[y][0]);
    return {st[x][0], res};
}

int main(){
    int n;
    while (scanf("%d", &n), n){
        for (int i = 1; i <= n; i++) g[i].clear();
        for (int i = 1; i <= n - 1; i++){
            int a, b, t;
            scanf("%d%d%d", &a, &b, &t);
            g[a].push_back({b, t});
            g[b].push_back({a, t});
        }
        dfs(1, 0, 0, 0);
        int q;
        scanf("%d", &q);
        while(q--){
            int a, b;
            scanf("%d%d", &a, &b);
            printf("%d\n", lca(a, b).second);
        }
    }
    return 0;
}