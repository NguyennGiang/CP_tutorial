#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 19;
long long dp[1 << N][N];
int val[N], mp[N][N];
int n, m, k;

int check(int state){
    int num = 0;
    for (int i = 0; i < n; i++){
        if ((1 << i) & state) num++;
    }
    return num == m;
}

int main(){
    int x, y, c;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) cin >> val[i];
    for (int i = 0; i < k; i++){
        cin >> x >> y >> c;
        x--, y--;
        mp[x][y] = c;
    }

    long long ans = 0;
    for (int i = 0; i < n; i++){
        dp[1 << i][i] = val[i];
    }

    for (int i = 0; i < (1 << n); i++){
        for (int j = 0; j < n; j++){
            if ((1 << j) & i){
                for (int k = 0; k < n; k++){
                    if (k != j && (1 << k) & i){
                        int state = i - (1 << j);
                        dp[i][j] = max(dp[i][j], dp[state][k] + mp[k][j] + val[j]);
                    }
                }
            }
        }

        if(check(i)){
            for (int j = 0; j < n; j++){
                ans = max(dp[i][j], ans);
            }
        }
    }
    cout << ans;
    return 0;
}
