#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#define fi first
#define se second
#define ll long long

using namespace std;

typedef pair <ll, pair <int, int>> piii;

const int maxn = 1e6;
int n, m;
int par[maxn];
vector <piii> edge;

void makeSet(int n){
    for (int i = 1; i <= n; i++){
        par[i] = i;
    }
}

int findSet(int u){
    if (u != par[u]){
        return par[u] = findSet(par[u]);
    }
    return par[u];
}

int unionSet(int u, int v){
    u = findSet(u);
    v = findSet(v);
    if (u == v) return false;

    par[u] = v;
    return true;
}

ll kruskal(){

    ll mst = 0;

    sort(edge.begin(), edge.end(), greater<piii>());
    makeSet(n);

    for (int i = 0; i < m; i++){
        int u = edge[i].se.fi;
        int v = edge[i].se.se;
        ll w = edge[i].fi;
        if (unionSet(u, v)){
            mst += w;
        } 
    }
    return mst;
}

void solve(int tc){
    cin >> n >> m;

    for (int i = 0; i < m; i++){
       int u, v; ll w;
       cin >> u >> v >> w;
       edge.push_back({w, {u, v}});
    }

    ll mst = kruskal();

    cout << "Case " << tc << ": " << n - 1 << " " << mst << '\n';
    edge.clear();
}

int main(){
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++){
        solve(i);
    }
    return 0;
}