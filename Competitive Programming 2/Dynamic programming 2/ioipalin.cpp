#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
int n, dp[N][N];
string s;

int solve(int l, int r){
    if (l >= r) return 0;
    if (dp[l][r] != -1) return dp[l][r];
    int q1 = INT_MAX, q2 = INT_MAX, q3 = INT_MAX;
    if (s[l] == s[r]){
        q1 = solve(l + 1, r - 1);
    }
    else {
        q2 = 1 + solve(l + 1, r);
        q3 = 1 + solve(l, r - 1);
    }
    return dp[l][r] = min(q1, min(q2, q3));
}

int main(){
    cin >> n >> s;
    memset(dp, -1, sizeof(dp));
    cout << solve(0, n - 1);
    return 0;   
}