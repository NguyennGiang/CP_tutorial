#include <bits/stdc++.h>
using namespace std;

const int N = 11;
int n, m;
vector <int> g[N];
bool vis[N];
vector <int> path;

bool solve(int u){
    if (path.size() == n){
        return true;
    }
    for (int v : g[u]){
        if(vis[v] == 0){
            vis[v] = 1;
            path.push_back(v);
            if(solve(v)){
                return true;
            }
            path.pop_back();
            vis[v] = 0;
        }
    }
    return false;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for (int i = 0; i < N; i++){
            g[i].clear();
            vis[i] = false;
        }
        for (int i = 0; i < m; i++){
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        bool check = false;
        for (int i = 1; i <= n; i++){
            path.clear();
            if (solve(i)){
                check = true;
                break;
            }
        }
        if(check){
            cout << "Yes\n";
        }
        else {
            cout << "No\n";
        }
        path.clear();
    }
    return 0;
}