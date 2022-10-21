#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll MOD = 1e9 + 7;
const int N = 50000, K = 101;
ll f[N][K];
ll a[N], s[N], dp1[K], dp[K];
ll k;
vector<vector<ll>> adj;

void dfs(ll v, ll p){
    for(ll c : adj[v]){
        if (c != v){
            dfs(c, v);
        }
    }
    fill(dp, dp + k + 1, 0);
    dp[a[v]] = 1;
    s[v] = a[v];
    for (auto c : adj[v]){
        s[v] += s[c];
        if (c == p) continue;
        fill(dp1, dp1 + k + 1; 0);
        for (int i = 0; i <= k; i++){
            for (int j = 0; j <= min(k, s[v]); j++){
                dp1[i+j] += (dp[i] * f[c][j]) % MOD;
                dp1[i+j] %= MOD;
            }
        }
        for (int i = 0; i <= k + 1; i++){
            dp[i] = dp1[i];
        }
    }
    dp[0] += 1;
    for (int i = 0; i <= k + 1; i++){
        f[v][i] = dp[i];
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        fill(s, s + n, 0);
        adj.clear();
        adj.resize(n);
        ll u, v;
        for (int i = 0; i < n - 1; i++){
            cin >> u >> v;
            adj[u-1].push_back(v-1);
            adj[v-1].push_back(u-1);
        }
        for (int i = 0; i < n; i++){
            for (j = 0; j <= k + 1; j++){
                f[i][j] = 0;
            }
        }

        dfs(0, -1);
        ll ans = 0;
        for (int i = 0; i < n; i++){
            ans += f[i][k];
            ans %= MOD;
        }
        if (k == 0){
            ans -= n;
        }
        cout << ans << endl;
    }
    return 0;
}