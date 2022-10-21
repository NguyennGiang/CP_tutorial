#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e4 + 5, M = 110, MOD = 1e9 + 7;
int d, n;
long long dp[N][2][M];
string k;

int solve(int x, int limit, int m){
    ll &t = dp[x][limit][m];
    if (~t) return t;
    if (!x) return t = (m == 0);
    t = 0;
    int up = limit ? k[x] - '0' : 9;
    for (int i = 0; i <= up; i++){
        t = (t + solve(x - 1, limit && i == up, (m + i) % d)) % MOD;
    }
    return t;
}

int main(){
    cin >> k >> d;
    n = k.size();
    memset(dp, -1, sizeof(dp));
    reverse(k.begin(), k.end());
    k = ' ' + k;
    cout << k << endl;
    cout << (solve(n, 1, 0) - 1 + MOD) % MOD;
}