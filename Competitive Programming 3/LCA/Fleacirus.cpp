#include <bits/stdc++.h>
using namespace std;

const int N = 50005;
int n, path[N], pn;
vector <int> g[N];

bool dfs(int u, int e, int pa){
    path[pn++] = u;
    if (u == e) return true;
    for (int i = 0; i < g[u].size(); i++){
        int v = g[u][i];
        if (v == pa) continue;
        if (dfs(v, e, u)) return true;
    }
    pn--;
    return false;
}

int main(){
    while(cin >> n && n != 0){
        for (int i = 0; i <= n; i++) g[i].clear();

        for (int u, v, i = 0; i < n - 1; i++){
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        int q;
        cin >> q;
        int s, e;
        while (q--){
            cin >> s >> e;
            pn = 0;
            dfs(s, e, -1);
            if (pn % 2) {
                cout << "The fleas meet at " << path[pn/2] << "." << endl;
            }
            else {
                int a = path[pn / 2];
                int b = path[pn / 2 - 1];
                if (a > b) swap(a, b);
                cout << "The fleas jump forever between " << a << " and " << b << "." << endl;
            }
        }
    }
    return 0;
}