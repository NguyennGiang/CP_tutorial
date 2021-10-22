#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
string s;
int n;
int dp[N][N];

int solve(int l, int r){
    if (dp[l][r] != -1) return dp[l][r];
    if (l == r) return dp[l][r] = 1;
    else if (r == l + 1){
        if (s[l] == s[r]){
            return dp[l][r] = 2;
        }
        return dp[l][r] = 1;
    }
    if (s[l] == s[r]) return 2 + solve(l + 1, r - 1);
    return dp[l][r] = max(solve(l + 1, r), solve(l, r - 1));
}

int main(){
    int t;
    cin >> t;
    getchar();
    while (t--){
        getline(cin, s);
        n = s.length();
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                dp[i][j] = -1;
            }
        }
        cout << solve(0, n - 1) << endl;
    }
    return 0;
}