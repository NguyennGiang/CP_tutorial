#include<bits/stdc++.h>
using namespace std;

int n, m, dp[10010][110];
int p[] = {1, 10, 100, 1000};

int solve(int num, int moves){
    if (moves == m) return num > n;
    if (dp[num][moves] != -1) return dp[num][moves];
    int ret = moves % 2;
    for (int i = 0; i < 4; i++){
        int r = (num / p[i]) % 10;
        int newNum = num + p[i];
        if (r == 9) newNum = num - 9 * p[i];
        if (moves % 2) ret = min(ret, solve(newNum, moves + 1));
        else ret = max(ret, solve(newNum, moves + 1));
    }
    return dp[num][moves] = ret;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        memset(dp, -1, sizeof(dp));
        int ans = solve(n, 0);
        if (ans == 1) cout << "Ada" << endl;
        else cout << "Vinit" << endl;
    }
    return 0;
}