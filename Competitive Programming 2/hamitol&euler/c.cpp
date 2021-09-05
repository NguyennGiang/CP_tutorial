#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
vector <int> g[N];
vector <bool> vis[N];
vector <int> res;
int a[1005];

void dfs(int u, int k){
    for (int i = 0; i < g[u].size(); i++){
        if (!vis[u][i]){    
            vis[u][i] = true;
            res.insert(res.begin() + k, g[u][i]);
            dfs(g[u][i], k + 1);
        }
    }
}

int main(){
    int t;
    cin >> t;
    int num = 0;
    int st = -1;
    for (int i = 0; i < N; i++){
        vis[i].clear();
        g[i].clear();
    }
    while(t--){
        int m;
        cin >> m;
        num += m;
        for (int i = 0; i <= m; i++){
            cin >> a[i];
            if (st == -1){
                st = a[i];
            }
            if (i){
                g[a[i-1]].push_back(a[i]);
                vis[a[i-1]].push_back(false);
            }
        }        
    }
    res.clear();
    res.push_back(st);
    dfs(st, 1);
    cout << num << " " << res.size() << endl;
    if (num != res.size() - 1){
        cout << 0 << endl;
    }
    else {
        cout << num;
        for (int i = 0; i < res.size(); i++){
            cout << " " << res[i];
        }
        cout << endl;
    }
    return 0;
}