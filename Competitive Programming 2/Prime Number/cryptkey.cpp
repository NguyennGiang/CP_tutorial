#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> prime_factor(ll k){
    vector <ll> res;
    for (ll i = 2; i * i <= k; i++){
        if (k % i == 0){
            while(k % i == 0){
                k /= i;
            }
            res.push_back(i);
        }
    }
    if (k > 1) res.push_back(k);
    return res;
}

void solve(){
    int n;
    cin >> n;
    vector <ll> a(n);
    for (ll &ai : a) cin >> ai;
    ll k; cin >> k;
    vector <ll> p = prime_factor(k);
    vector <ll> b(p.size(), 0);

    for (ll ai : a){
        for (int i = 0; i < b.size(); i++){
            if (ai % p[i] == 0){
              b[i] = __gcd(ai, b[i]);
            }
        }
    }
    bool oce = true;
    for (ll bi : b){
      oce &= (bi > 0 && k % bi == 0);
    }
    cout << (oce? "YES" : "NO") << '\n';
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}