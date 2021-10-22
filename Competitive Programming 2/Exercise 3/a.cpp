#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll MOD = 1e9 + 7;

long long bigMod(ll a, ll b){
    if (b == 0){
        return 1;
    }
    ll x = bigMod(a, b / 2);
    x  = (x * x) % MOD;
    if (b & 1){
        x = (x * a) % MOD;
    }
    return x;
}

int main(){
    int t;
    cin >> t;
    ll inv = bigMod(6, MOD - 2);
    while (t--){
        ll n;
        cin >> n;
        n++;
        ll ans = (n * (n + 1)) % MOD;
        ans = (ans * (n + 2)) % MOD;
        ans = (ans * inv) % MOD;
        cout << ans << endl;
    }
    return 0;
}