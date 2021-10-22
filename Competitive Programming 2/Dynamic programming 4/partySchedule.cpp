#include <bits/stdc++.h>
using namespace std;

// const int N = 505;
// const int M = 105;
// int dp[N][M];

int main(){
    int w, n;
    while (1){
        cin >> w >> n;
        if (w == 0 && n == 0) break;

        vector <pair <int, int>> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i].first >> a[i].second;
        }
        int dp[n+1][w+1];
        
        for (int i = 0; i <= w; i++){
            dp[0][i] = 0;
        }
        for (int i = 0; i <= n; i++){
            dp[i][0] = 0;
        }

        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= w; j++){
                if (a[i-1].first <= j){
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-a[i-1].first] + a[i-1].second);
                }
                else dp[i][j] = dp[i-1][j];
            }
        }

        int maxFun = dp[n][w];
        int minMoney = 0;
        for (int i = 0; i <= w; i++){
            if (dp[n][i] == maxFun){
                minMoney = i;
                break;
            }
        }
        cout << minMoney << " " << maxFun << endl;
    } 
    return 0;
}