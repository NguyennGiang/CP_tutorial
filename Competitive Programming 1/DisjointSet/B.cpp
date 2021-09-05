#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int maxn = 1e5;

bool oce = 1;
int m, n, q;
int par[maxn];

void makeSet() {
    for (int i = 1; i <= n; i++){
        par[i] = i;
    }
}

int findSet(int s) {
    if (s != par[s]) {
        return par[s] = findSet(par[s]);
    }
    return par[s];
}

void unionSet(int u, int v) {
    u = findSet(u);
    v = findSet(v);

    if (u == v) {
        oce = 0;
        return;
    }
    oce = 1;
    par[u] = v;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; 
    cin >> t; 
    while(t--) {
        cin >> m >> n >> q; 

        vector <pair <int ,int>> e(m + 1);
        vector <int> w(m + 1);

        for (int i = 1; i <= m; i++) {
            cin >> e[i].fi >> e[i].se >> w[i];
        }

        while(q--) {
            int k; 
            cin >> k;
            int s; 
            cin >> s; 
            vector <int> ww(w);

            while(s--) {
                int t, w; 
                cin >> t >> w; 
                ww[t] = w;
            }

            makeSet();

            for (int i = 1; i <= m; i++) {
                if (ww[i] < ww[k]) {
                    unionSet(e[i].fi, e[i].se);
                }
            }

            unionSet(e[k].fi, e[k].se);

            if (oce) {
                cout << "NO\n";
            }
            else {
                cout << "YES\n";
            }

        }

    }

    return 0;
}