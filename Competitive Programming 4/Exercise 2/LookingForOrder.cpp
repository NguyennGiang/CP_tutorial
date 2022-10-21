#include <bits/stdc++.h>
using namespace std;

const int inf = 0x3f3f3f3f;
int dp[1 << 24], dis[25][25], pres[1 << 24], path[550], cnt, n;
pair<int, int> a[25];

int main(){
    int x, y;
    cin >> x >> y;
    cin >> n;
    a[n] = {x, y};
    for (int i = 0; i < n; i++){
        cin >> x >> y;
        a[i] = {x, y};
    }

    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= n; j++){
            dis[i][j] = (a[i].first - a[j].first) * (a[i].first - a[j].first) + (a[i].second - a[j].second) * (a[i].second - a[j].second);
        }
    }

    memset(dp, inf, sizeof(dp));
    dp[0] = 0;
    for (int i = 0; i < (1 << n); i++){
        if(dp[i] == inf) continue;
        for (int j = 0; j < n; j++){
            if (((1 << j) & i) == 0){
                for (int k = j; k < n; k++){
                    if (((1 << k) & i) == 0){
                        int tmp = i | (1 << j) | (1 << k);
                        int d = dis[j][k] + dis[n][j] + dis[n][k];
                        if (dp[tmp] > dp[i] + d){
                            dp[tmp] = dp[i] + d;
                            pres[tmp] = i;
                        }
                    }
                }
                break;
            }
        }
    }
    cout << dp[(1 << n) - 1] << endl;
    for (int i = (1 << n) - 1; i != 0; i = pres[i]){
        int tmp = pres[i] ^ i;
        path[cnt++] = 0;
        for (int j = 0; j < n; j++){
            if ((1 << j) & tmp){
                path[cnt++] = j + 1;
            }
        }
    }
    path[cnt++] = 0;
    for (int i = cnt - 1; i >= 0; i--){
        cout << path[i] << ' ';
    }
    return 0;
}