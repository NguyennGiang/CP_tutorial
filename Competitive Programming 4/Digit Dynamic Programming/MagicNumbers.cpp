#include<bits/stdc++.h>
using namespace std;

const int N = 2005, MOD = 1e9 + 7;
int m, k, len;
string s;
long long dp[N][N][2], digit[N];
long long ans;

long long dfs(int pos, int rem, int up){
    if (pos == len) return rem == 0;
    if (dp[pos][rem][up] != -1) return dp[pos][rem][up];
    int end = (up? digit[pos] : 9);
    long long ans = 0;
    for (int i = 0; i <= end; i++){
        if(pos % 2 == 0 && i == k) continue;
        if (pos % 2 == 1 && i != k) continue;
        ans += dfs(pos + 1, (rem * 10 + i) % m, up && i == end);
        ans %= MOD;

    }
    dp[pos][rem][up] = ans;
    return ans;
}

long long get(){
    len = s.length();
    for (int i = 0; i < len; i++){
        digit[i] = s[i] - '0';
    }
    return dfs(0, 0, 1);
}

int check(){
    int t = 0;
    for (int i = 0; i < len; i++){
        if (i % 2 == 0 && digit[i] == k) return 0;
        if (i % 2 == 1 && digit[i] != k) return 0;
        t = t * 10 + digit[i];
        t %= m;
    }
    return t == 0;
}

int main(){
    cin >> m >> k;
    long long ans = 0;
    memset(dp, -1, sizeof(dp));
    cin >> s;
    long long a = get();
    ans += check();
    memset(dp, -1, sizeof(dp));
    cin >> s;
    long long b = get();
    ans += b - a;
    ans = (ans + MOD) % MOD;
    cout << ans << endl;
    return 0;
}