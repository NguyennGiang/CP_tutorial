#include <iostream>
#include <vector>
#include <algorithm>
#define nl '\n'
using namespace std;

const int N = 1e5 + 10;

vector <int> graph[N];
bool vis[N];
vector <int> topoSort;
int n, m;

void init(){
    for (int i = 0; i <= n; i++){
        graph[i].clear();
        vis[i] = false;
        topoSort.clear();
    }
}

void dfs(int u){
    vis[u] = 1;

    for (int v : graph[u]){
        if (!vis[v]){
            dfs(v);
        }
    }
    topoSort.push_back(u); 
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;

        init();

        while(m--){
            int x, y;
            cin >> x >> y;
            graph[x].push_back(y);
        }

        for (int i = 1; i <= n; i++){
            if (!vis[i]){
                dfs(i);
            }
        }n

        reverse(topoSort.begin(), topoSort.end());
        int result = 0;

        for (int i = 1; i <= n; i++){
            vis[i] = false;
        }

        for (int i = 0; i < n; i++){
            if (!vis[topoSort[i]]){
                result ++;
                dfs(topoSort[i]);
            }
        }
        cout << result << nl;
    }
    return 0;
}