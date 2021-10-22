#include <bits/stdc++.h>
using namespace std;

int dp[31];

int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        for (int i = 0; i < n; i++){
            int p, w;
            cin >> p >> w;
            for (int j = 30; j >= w; j--){
                dp[j] = max(dp[j], dp[j-w] + p);
            }
        }
        int g;
        cin >> g;
        int ans = 0;
        while (g--){
            int mw;
            cin >> mw;
            ans += dp[mw];
        }
        cout << ans << endl;
        memset(dp, 0, sizeof(dp));
    }
    return 0;
}