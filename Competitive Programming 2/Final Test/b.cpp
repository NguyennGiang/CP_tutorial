#include <bits/stdc++.h>
using namespace std;

int m, n;
int p[4005], f[4005];
int dp[105][10000 + 5];

int solve(int i , int w){
    if (w > m && m <= 1800){
        return -1000;
    }

    if (w > m + 200){
        return -1000;
    }

    if (i == n){
        if (w > m && w <= 2000){
            return -1000;
        }
        return 0;
    }

    if (dp[i][w] != -1) return dp[i][w];

    return dp[i][w] = max(solve(i + 1, w), solve(i + 1, w + p[i]) + f[i]);
}

int main(){

    while (cin >> m >> n){
        memset(dp, -1, sizeof(dp));
        memset(p, 0, sizeof(p));
        memset(f, 0, sizeof(f));

        for (int i = 0 ; i < n; i++){
            cin >> p[i] >> f[i];
        }
        cout << solve(0, 0) << endl;
    }
    return 0;
}