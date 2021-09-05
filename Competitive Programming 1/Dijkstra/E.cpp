#include <bits/stdc++.h>
#define maxn 1000005
#define INF 1e9
#define fi first
#define se second
#define ll long long
#define pii pair <int ,int>
#define pll pair <ll, ll>
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

int n, m, s, l;
vector<vector<pii>> adj;
vector<int> dist;

void Dijkstra(int s){
    priority_queue <pii, vector<pii>, greater<pii> > pq; 
    pq.push({0, s});
    dist[s] = 0;
    while(!pq.empty()){
        pii tmp = pq.top();
        pq.pop();
        int u = tmp.se;
        if(dist[u] != tmp.fi) continue;

        for (int i = 0; i < adj[u]. size(); i++){\
            int w = adj[u][i].fi;
            int v = adj[u][i].se;
            if (dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    fast_io;

    cin >> n >> m >> s; 
     
    adj.assign(n+1, vector<pii>());
    dist.assign(n+1, INF);   

    for (int i = 0; i < m; i++){
        int u, v, w; 
        cin >> u >> v >> w; 
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    cin >> l; 

    Dijkstra(s);

    int ans = 0; 
    for (int i = 1; i <= n; i++){
        if (dist[i] == l){
            ans++;
        }
        for (int j = 0; j < adj[i].size(); j++){
            int v = adj[i][j].se;
            int w = adj[i][j].fi;
            if (i >= v) continue;

            int df0 = l - dist[i];
            int df1 = l - dist[v];
            bool oc0 = false; 
            bool oc1 = false; 
            if(0 < df0 && df0 < w && l <= dist[v] + w - df0){
                ans++;
                oc0 = true;
            }
            if(0 < df1 && df1 < w && l <= dist[i] + w - df1){
                ans++;
                oc1 = true;
            }
            if(oc0 && oc1 && df0 + df1 == w){
                ans--;
            }
        }   
        
    }

    cout << ans;
}