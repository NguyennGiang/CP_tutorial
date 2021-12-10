#include <bits/stdc++.h>
using namespace std;
#define KAMEHAMEHA ios_base::sync_with_stdio(0); cin.tie(0);
#define ll long long
const ll N = 3e6 + 5, MOD = 998244353;
ll zl[N], zr[N], dp[N], pre[N];

ll sub(ll a, ll b){
    ll p = a - b;
    if (p < 0) p += MOD;
    return p;
}
ll add(ll a, ll b){
    ll p = a + b;
    if (p >= MOD) p -= MOD;
    return p;
}

int main(){
    KAMEHAMEHA

    string a, l, r;
    cin >> a >> l >> r;
    ll n = l.size(), m = r.size();

    string p = l + "#" + a, q = r + "#" + a;

    for (ll i = 1, l = 0, r = 0; i < p.length(); i++){
        if (i <= r) zl[i] = min(zl[i-l], r - i + 1);
        while(i + zl[i] < p.length() && p[zl[i]] == p[i + zl[i]]){
            zl[i]++;
        }
        if (i + zl[i] - 1 > r){
            l = i, r = i + zl[i] - 1;
        }
    }

    for (ll i = 1, l = 0, r = 0; i < q.length(); i++){
        if (i <= r) zr[i] = min(zr[i-l], r - i + 1);
        while(i + zr[i] < q.length() && q[zr[i]] == q[i + zr[i]]){
            zr[i]++;
        }
        if (i + zr[i] - 1 > r){
            l = i, r = i + zr[i] - 1;
        }
    }
    ll pp = a.size();
    dp[pp] = 1;
    pre[pp] = 1;
    for (ll i = pp - 1; i >= 0; i--){
        if (a[i] == '0'){
            if (l.size() == 1 && l == "0") dp[i] = dp[i+1];
            else dp[i] = 0;
            pre[i] = add(pre[i+1], dp[i]);
            continue;
        }

        ll lr = i + n - 1, rr = i + m - 1;
        ll pl = zl[i + n + 1], pr = zr[i + m + 1];

        if(pl < n && i + pl < pp && a[i + pl] < l[pl]) lr++;
        if(pr < m && i + pr < pp && a[i + pr] > r[pr]) rr--;

        if(lr > rr) dp[i] = 0;
        else dp[i] = sub(pre[lr + 1], (rr + 2 > pp ? 0 : pre[rr + 2]));
        pre[i] = add(pre[i+1], dp[i]);
    }
    cout << dp[0] << endl;
    return 0;
}
