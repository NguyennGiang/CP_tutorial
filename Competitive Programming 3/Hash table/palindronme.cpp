#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MOD = 1e9 + 7;
const int N = 5e6 + 5;
int dp[N];

int main(){
    string s;
    while(cin >> s){
        memset(dp, 0, sizeof(dp));
        int l = s.length();
        if (l == 0){
            cout << 0 << endl;
            continue;
        }

        dp[0] = 1;
        ll ans = 1, p = s[0], q = s[0];
        ll tmp = 1;
        // Base = 131;
        for (int i = 1; i < l; i++){
            p = (p * 131 + s[i]) % MOD;
            tmp = (tmp * 131) % MOD;
            q = (str[i] * tmp + q) % MOD;
            // q = left, q = right;
            if (p == q){
                dp[i] = dp[(i-1)/2] + 1;
                ans += dp[i];
            }
        }
        cout << ans << endl;
    }
    return 0;
}

// Time: O(n);