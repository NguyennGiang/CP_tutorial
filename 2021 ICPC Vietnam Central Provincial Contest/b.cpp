#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    int nev = 0, pos = 0, zero = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 0) zero++;
        else if (a[i] < 0) nev++;
        else pos++;
    }

    long long res = 1, prod = 1;
    for (int v : a) prod = (prod * v) % MOD;

    if (zero >= 2) res = 0;
    else {
        if (zero == 1){
            if (nev % 2 == 0){
                for (int v : a){
                    if (v != 0){
                        res = (res * v) % MOD;
                    }
                }
            }
            else {
                res = 0;
            }
        }
        else {
            if (nev % 2 ==0){
                res = prod;
            }
            else {
                int temp = INT_MIN;
                for (int v : a){
                    if (v < 0){
                        if (v > temp){
                            temp = v;
                        }
                    }
                }
                for (int v : a){
                    if (v != temp){
                        res = (res * v) % MOD;
                    }
                }
            }
        }
    }
    cout << res << endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
