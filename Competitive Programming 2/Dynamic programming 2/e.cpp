#include <bits/stdc++.h>
using namespace std;

const int N = 205;
int n, q, d, m;
int nums[N];
long long dp[N][N][15];

long long solve(int i, int sum, int c){
    if (c == m && sum == 0){
        return 1;
    }
    if (c == m && sum != 0){
        return 0;
    }
    if (i == n){
        return 0;
    }

    if (dp[i][sum][c] != -1) return dp[i][sum][c];

    dp[i][sum][c] = solve(i + 1, sum % d, c) + solve(i + 1, (sum + nums[i] + 1000 * d) % d, c + 1);
    return dp[i][sum][c];
}

int main(){
    int tc = 1;

    while (1){
        cin >> n >> q;
        if (!n && !q) break;

        for (int i = 0; i < n; i++) cin >> nums[i];

        cout << "SET " << tc++ << ": \n";
        for (int i = 1; i <= q; i++){
            cin >> d >> m;
            memset(dp, -1, sizeof(dp));
            cout << "QUERY " << i << ": " << solve(0, 0, 0) << endl;
        }
    }
    return 0;
}