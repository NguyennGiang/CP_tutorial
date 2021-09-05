#include <bits/stdc++.h>
using namespace std;
#define ll long long

set <ll> at[3];

void solve(){
    ll n, k;
    cin >> n >> k;
    ll ans = 1e12;
    ans = min(ans, *at[k].lower_bound(n)); 
    cout << ans << '\n';
}

int main(){
    int t;
    cin >> t;
    for (ll i = 0; i <= 9; i++){
        ll ans = 0;
        for (ll j = 0; j < 12; j++){
            ans = ans * 10 + i;
            at[1].insert(ans);
        }
    }

    for (ll i = 0; i <= 9; i++){
        for (ll j = i + 1; j <= 9; j++){
            for (ll k = 0; k < 11; k++){
                for (ll m = 0; m < (1 << k); m++){
                ll ans = 0;
                    for (ll n = 0; n < k; n++){
                        ll v = ( ((m >> n) & 1) ? i : j);
                        ans = ans * 10 + v;
                    }
                    at[2].insert(ans); 
                }
            }
        }
    }
    while (t--){
        solve();
    }
    return 0;
}
