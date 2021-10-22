#include <bits/stdc++.h>
using namespace std;

const int M = 1e6+5;
const int N =  5005;
int dp[N][N];

char a[M], b[N];
int nextPos[M][26];
int m, n;

void minimize(int &a, int b){
    if (a == -1 || a > b) a = b;
}

int main(){
    cin >> a + 1 >> b + 1;
    m = strlen(a + 1); n = strlen(b + 1);
    for (int c = 0; c < 26; c++){
        for (int i = m - 1; i >= 0; i--){
            nextPos[i][c] = (a[i+1] - 'A' == c) ? i + 1 : nextPos[i+1][c];
        }
    }
    int maxLen = min(m, n);
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j <= i; j++){
            if (dp[i][j] >= 0){
                minimize(dp[i+1][j], dp[i][j]);
                int new_value = nextPos[dp[i][j]][b[i+1] - 'A'];
                if (new_value > 0){
                    minimize(dp[i+1][j+1], new_value);
                }
            }
        }
    }
    int ans = 0;
    for (int j = maxLen; j > 0; j--){
        for (int i = j; i <= n; i++){
            if (dp[i][j] >= 0) ans = j;
        }
        if (ans) break; 
    }
    cout << ans << endl;
    return 0;
}

