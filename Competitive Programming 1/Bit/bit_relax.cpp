#include<bits/stdc++.h>
#define ll long long
using namespace std; 
const int Maxn = 3e5 + 10;

ll num[Maxn], dp[2][1 << 20]; 

int main() {
    ll n;
    cin >> n; 
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
    }
    ll ans = 0;
    memset(dp, 0, sizeof(dp));
    int cur = 0;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        cur ^= num[i];
        ans += dp[i&1][cur]++;
    }
    cout << ans << '\n';
    return 0;
    
}