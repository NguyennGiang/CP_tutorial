#include <bits/stdc++.h>
using namespace std;

int dp[6005];
int n, w[3005], c[3005];

int main(){
    while (cin >> n && n != 0){
        for (int i = 1; i <= n; i++){
            cin >> w[i] >> c[i];
        }
        memset(dp, 0, sizeof(dp));
        for (int i = n; i >= 1; i--){
            for (int j = 6000; j >= w[i]; j--){
                if (dp[j] < dp[min(j - w[i], c[i])] + 1){
                    dp[j] = dp[min(j - w[i], c[i])] + 1;
                }
            }
        }
        cout << dp[6000] << endl;
    }
    return 0;
}