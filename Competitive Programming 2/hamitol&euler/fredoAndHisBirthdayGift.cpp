#include <bits/stdc++.h>
using namespace std;
#define N 20

bool adj[N][N];
bool vis[N];
vector <int> path;
int res = 0;
int n, m;

void solve(int u){
    if (path.size() - 1 > res){
        res = path.size() - 1;
    }
    if (res == n - 1){
        return;
    }

    for (int v = 1; v <= n; v++){
        if (adj[u][v] && (!vis[v])){
            vis[v] = true;
            path.push_back(v);
            solve(v);
            vis[v] = false;
            path.pop_back();
        }
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){  
        cin >> n >> m;
        for (int i = 1; i <= n; i++){
            vis[i] = false;
            for (int j = 1; j <= n; j++){
                adj[i][j] = false;
            }
        }
        while(m--){
            int a, b;
            cin >> a >> b;
            adj[a][b] = 1;
            adj[b][a] = 1;
        }

        for (int i = 1; i <= n; i++){
            memset(vis, false, sizeof(vis));
            path.clear();
            vis[i] = true;
            path.push_back(i);
            res = 0;
            solve(i);
            cout << res << " ";
        }
        cout << '\n';
    }
    return 0;
}