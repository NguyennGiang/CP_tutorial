#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int mod1 = 1e9 + 7, mod2 = 999999937;
const int B1 = 131, B2 = 151;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    vector <ll> p1(n + 1, 1), h1(n + 1, 0);
    vector <ll> p2(n + 1, 1), h2(n + 1, 0);
    for (int i = 1; i <= n; i++){
        p1[i] = (p1[i-1] * B1) % mod1;
        p2[i] = (p2[i-1] * B2) % mod2;
        h1[i] = (h1[i-1] * B1 + s[i-1] - 'A' + 1) % mod1;
        h2[i] = (h2[i-1] * B2 + s[i-1] - 'A' + 1) % mod2;

    }

    vector <int> sum(n + 1, 0);
    sum[n] ++;
    for (int i = 1; i < n; i++){
        int l = 1, r = n - i;
        int ans = 0;
        while (l <= r){
            int m = (l + r) / 2;
            ll x1 = h1[m];
            ll x2 = h2[m];
            int outi = i + m;
            ll ys1 = (outi <= n ? h1[outi] : h1[n]);
            ll ys2 = (outi <= n ? h2[outi] : h2[n]);
            ll y1 = (ys1 - (h1[i] * p1[m]) % mod1 + mod1) % mod1;
            ll y2 = (ys2 - (h2[i] * p2[m]) % mod2 + mod2) % mod2;
            if (x1 == y1 && x2 == y2){
                ans = m;
                l = m + 1;
            }
            else r = m - 1;
        }
        //cout << ans << endl;
        sum[ans] ++;
    }
    //for (int i = n; i >= 1; i--) cout << sum[i] << " ";
    for (int i = n - 1; i >= 1; i--) sum[i] += sum[i+1];

    vector <pair<ll, ll>> res;
    for (ll len = 1; len <= n; len ++){
        ll x1 = h1[len];
        ll x2 = h2[len];
        ll y1 = (h1[n] - (h1[n-len] * p1[len]) % mod1 + mod1) % mod1;
        ll y2 = (h2[n] - (h2[n-len] * p2[len]) % mod2 + mod2) % mod2;
        if (x1 == y1 && x2 == y2){
            res.push_back({len, sum[len]});
        }
    }
    cout << res.size() << endl;
    for (auto x : res) cout << x.first << " " << x.second << endl;
    return 0;
}