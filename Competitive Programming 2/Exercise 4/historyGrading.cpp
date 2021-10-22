#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    string s;
    ll n;
    vector <int> a(25), b(25);
    vector <vector<int>> dp(25, vector <int> (25, 0));
    while (getline(cin, s)){
        vector <int> v;
        ll x;
        stringstream ss(s);
        while (ss >> x){
            v.push_back(x);
        }
        if (v.size() == 1){
            n = v[0];
            getline(cin, s);
            stringstream iss(s);
            ll i = 0;
            while(iss >> x){
                a[x] = ++i;
                //cout << x << " " << i;
            }
            continue;
        }

        for (int i = 0; i < n; i++){
            b[v[i]] = i + 1;
        }
        for (int i = 0; i < n; i++){
            dp[i][0] = 0;
            dp[0][i] = 0;
        }
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                if (a[i] == b[j]) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        cout << dp[n][n] << endl;
    }
}

int main(){
    solve();
    return 0;
}