#include <bits/stdc++.h>
using namespace std;

const int N = 255;
long long dp[N];

// long long solve(vector <int> &coins, int n, int m){
//     if (n == 0) return 1;
//     if (n < 0) return 0;
//     if (dp[n] != -1) return dp[n];
//     long long res = 0;
//     for (int i = 0; i < m; i++){
//         res += solve(coins, n - coins[i], m);
//     }
//     return dp[n] = res;
// }

int main(){
    int n, m;
    cin >> n >> m;
    vector <int> coins(m);
    for (int &x : coins) cin >> x;
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int coin : coins){
        for (int j = coin; j <= n; j++){
            dp[j] += dp[j - coin];
        }
    }
    cout << dp[n];
    return 0;
}