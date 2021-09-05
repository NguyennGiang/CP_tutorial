#include <iostream>
#include <vector>
#include <algorithm>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N = 1e5 + 5;
const int M = 2e5 + 5;

int n, m;
int par[N], bm;
ll b[M];
pair <int, pair<int, int>> a[M];
vector <pair <int, int>> v[N];

int fin(int x){
    if (x != par[x]){
        return par[x] = fin(par[x]);
    }
    return par[x];
}

bool unionSet(int u, int v){
    u = fin(u);
    v = fin(v);

    if (u == v) return false;

    par[u] = v;
    return true;
}

int dfs(int x,int fa){
    int r = 1;
    for (int i = 0; i < v[x].size(); i++)
    if (v[x][i].fi != fa){
        int k = dfs(v[x][i].fi, x);
        b[v[x][i].se] += 1ll * k * (n - k);
        r += k;
    }
    return r;
}

void sol(){
    sort(a, a + m);

    for (int i = 1; i <= n; i++) par[i] = i;

    for (int i = 0; i < m; i++){
        int x = a[i].se.fi;
        int y = a[i].se.se;
        int z = a[i].fi;

        if (unionSet(x, y)){
            v[x].push_back({y, z});
            v[y].push_back({x, z});
            bm = z;
        }
    }
    dfs(1, 1);

    for (int i = 0; i < bm; i++){
        cout << b[i] << " ";
    }

    for (int i = 0; i < bm; i++){
        b[i+1] += b[i] / 2;
        b[i] %= 2;
    }
    while (b[bm] > 1){
        b[bm + 1] = b[bm] / 2;
        b[bm] %= 2;
        bm++;
    }

    // for (int i = bm; i >= 0; i--){
    //    putchar('0' + b[i]);
    // }
    // cout << '\n';
}

int main(){
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        cin >> a[i].se.fi >> a[i].se.se >> a[i].fi;
    }
    sol();
}