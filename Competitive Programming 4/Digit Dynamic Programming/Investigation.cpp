#include<bits/stdc++.h>
using namespace std;

const int N = 15;
int dp[N][10 * N][10 * N][2];
int a, b, k;
int len;
int digit[N];

int dfs(int pos, int r, int sum, int limit){
    if (pos == -1){
        return r == 0 && sum == 0;
    }
    if (dp[pos][r][sum][limit] != -1) return dp[pos][r][sum][limit];
    int up = limit ? digit[pos] : 9;
    int ans = 0;
    for (int i = 0; i <= up; i++){
        ans += dfs(pos - 1, (r + i) % k, (sum * 10 + i) % k, limit && i == up);
    }
    dp[pos][r][sum][limit] = ans;
    return ans;
}

int solve(int n){
    len = 0;
    if (!n){
        digit[len++] = 0;
    }
    while(n){
        digit[len++] = n % 10;
        n = n/10;
    }
    return dfs(len - 1, 0, 0, 1);
}

int main(){
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++){
        cin >> a >> b >> k;
        memset(dp, -1, sizeof(dp));
        cout << "Case " << tc << ": ";
        int ans = solve(b);
        if (a > 0){
            memset(dp, -1, sizeof(dp));
            ans -= solve(a - 1);
        }
        cout << ans << endl;
    }
}