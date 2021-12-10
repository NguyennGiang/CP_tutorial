#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
long long pa[N], level[N], length[N];
int n;

long long cost(int s, int t){
    int u = s, v = t;
    while (level[u] > level[v]){
        u = pa[u];
    }
    while (level[v] > level[u]){
        v = pa[v];
    }
    while (u != v){
        u = pa[u];
        v = pa[v];
    }
    return length[s] + length[t] - length[u] - length[v];
}

int main(){
    while (cin >> n && n != 0){
        pa[0] = 0;
        length[0] = 0;
        level[0] = 0;

        for (int u, w, i = 1; i < n; i++){
            cin >> u >> w;
            pa[i] = u;
            level[i] = level[u] + 1;
            length[i] = length[u] + w;
        }
        int q, s, t;
        cin >> q;
        while (q--){
            cin >> s >> t;
            cout << cost(s, t) << " ";
        }
        cout << endl;
    }
    return 0;
}