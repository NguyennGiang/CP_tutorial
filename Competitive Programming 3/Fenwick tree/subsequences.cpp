#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e5 + 5;
const int M = 1e6 + 5;
const ll MOD = 1e9 + 7;
ll n, tree[M];

ll sum(ll x){
    ll sum = 0;
    while (x){
        sum += tree[x];
        sum %= MOD;
        x -= x & -x;
    }
    return sum;
}

void add(ll x, ll c){
    while (x < 1e6 + 5){
        tree[x] += c;
        tree[x] %= MOD;
        x += x & -x;
    }
}

ll a[N], dp[M], pre[M]; 

int main(){
    ll ans = 0;
    cin >> n;
    memset(pre, -1, sizeof(pre));
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++){
        dp[i] = sum(a[i]) * a[i] + a[i];
        if (pre[a[i]] != - 1) dp[i] -= pre[a[i]];
        dp[i] = (dp[i] % MOD + MOD) % MOD;
        ans += dp[i];
        ans = (ans % MOD + MOD) % MOD;
        pre[a[i]] = sum(a[i]) * a[i] + a[i];
        add(a[i], dp[i]);
    }
    cout << ans;
    return 0;
}