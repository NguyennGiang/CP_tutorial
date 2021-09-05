#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll ans = ceil((double) sqrt(n));
        ll res = sqrt(n);
        res *= res;
        if (n - res == 0) cout << ans << " " << 1 << '\n';
        else if (n - res <= ans) cout << n - res<< " " << ans << '\n';
        else {
            ll x = ans * ans;
            cout << ans << " " << x - n + 1 << '\n';
        }
    }
    return 0;
}