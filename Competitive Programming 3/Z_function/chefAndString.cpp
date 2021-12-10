#include<bits/stdc++.h>
using namespace std;
#define KAMEHAMEHA ios_base::sync_with_stdio(0); cin.tie(0);

const int mod = 1e9 + 7;
const int N = 100010;
int ans[N], cnt[N], cnt2[N];

vector <int> z_function(string s){
    int n = int(s.length());
    vector<int> z(n, 0);
    for (int i = 1, l = 0, r = 0; i < n; i ++){
        if (i <= r){
            z[i] = min(r - i + 1, z[i - l]);
        };
        while(i + z[i] < n && s[z[i]] == s[z[i] + i]){
            z[i]++;
        }
        if (i + z[i] - 1 > r){
            l = i, r = i + z[i] - 1;
        }
    }
    return z;
}

int fact[N], inv[N];

int bin_pow(int o, int s){
    if (s == 0) return 1;
    if (s == 1) return o % mod;
    int d = bin_pow(o, s/2);
    d = (d * 1ll * d) % mod;
    if (s % 2 == 1){
        d = (d * 1ll * o) % mod;
    }
    return d;
}

int C(int n, int k){
    int res = 1;
    res = (res * 1ll * fact[n]) % mod;
    res = (res * 1ll * inv[k]) % mod;
    res = (res * 1ll * inv[n-k]) % mod;
    return res;
}

int main(){
    KAMEHAMEHA
    int t; cin >> t;
    while (t--){
        int n, q;
        string s;
        cin >> n >> q >>  s;

        fact[0] = inv[0] = 1;
        ans[0] = 0;
        for (int i = 1; i <= n; i++){
            fact[i] = (fact[i-1] * 1ll * i) % mod;
            inv[i] = bin_pow(fact[i], mod - 2);
            ans[i] = 0;
            cnt2[i] = 0;
        }

        for (int i = 0; i < n; i++){
            vector <int> zz = z_function(s.substr(i, n - i));
            for (int j = 0; j <= n; j++){
                cnt[j] = 0;
            }

            for (int x : zz) {
                cnt[0]++;
                cnt[x+1]--;
            }
            //for (int i = 0; i <= n; i++) cout << cnt[i] << ' ' << cnt2[i] << ' ';
           // cout << endl;
            for (int i = 1; i <= n; i++){
                cnt[i] += cnt[i-1];
                cnt2[cnt[i]] ++;
            }
            ans[1] += n - i;
        }
        //cnt2[i] : number of different subtrings appear i times
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= i; j++){
                ans[j + 1] = (1ll * ans[j + 1] + cnt2[i] * 1ll * C(i, j)) % mod;
            }
        }
        while (q--){
            int x; cin >> x;
            if (x > n){
                cout << 0 << endl;
            }
            else {
                cout << ans[x] << endl;
            }
        }
    }
    return 0;
}

