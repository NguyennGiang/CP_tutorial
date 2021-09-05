#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5;

int par[maxn];
int n;

void makeSet() {
    for (int i = 1; i <= n; i++) {
        par[i] = i;
    }
}

int findSet(int s) {
    return par[s] == s ? s : (par[s] = findSet(par[s]));
}

void unionSet(int u, int v) {
    int pu = findSet(u);
    int pv = findSet(v);

    if (pu == pv) {
        return;
    }

    par[pu] = pv;
}

vector <pair <int, int>> v;
vector <int> ans;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    makeSet();

    int x, y;

    for (int i = 1; i < n; i++) {
        cin >> x >> y;

        if (findSet(x) != findSet(y)) {
            unionSet(x, y);
        }

        else {
            v.push_back({x, y});
        }
    }

    for (int i = 1; i <= n; i++) { 
        if (findSet(i) == i) {
            ans.push_back(i);
        }
    }

    int cnt = int (ans.size()) - 1;

    cout << cnt << '\n';

    if (cnt != 0){
        for (int i = 0; i < v.size(); i++){
            cout << v[i].first << " " << v[i].second << " " << ans[i] << " " << ans[i + 1] << '\n';
        }
    }

    return 0;
}