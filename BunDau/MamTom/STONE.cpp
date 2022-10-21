#include <bits/stdc++.h>
#define N 2020
#define FOR(i, a, b) for (int i = a; i<=b; i++)
#define FORD(i, a, b) for (int i = a; i>=b; i--)
#define REP(i, a) for (int i = 1; i<=a; i++)
 
using namespace std;
 
int f[N], c[N], n, a, b;
long long s[N];
bool g[N][N];
 
const int inf = 1e9;
 
bool solve1(int k, long long limit) { // N^2 && a == 1
    REP(i, n) f[i] = inf;
    f[0] = 0;
    REP(i, n) FOR(j, 1, i)
        if ((((s[i] - s[j - 1]) | limit) >> k) == (limit >> k)) {
        f[i] = min(f[i], f[j - 1] + 1);
    }
    return f[n] <=b;
}
 
bool solve2(int k, long long limit) { //N^3 && a > 1
    FOR(i, 0, n) REP(j, n) g[i][j] = false;
    g[0][0] = true;
    FOR(kk, 1, b)
        FOR(j, 1, n)
            FOR(i, j, n) {
        if (((((s[i] - s[j - 1]) | limit) >> k) == (limit >> k)) && g[kk - 1][j - 1])
            g[kk][i] = true;
    }
    FOR(i, a, b) if (g[i][n]) return true;
    return false;
}
 
bool ok(int k, long long limit) {
    if (a == 1) return solve1(k, limit);
    return solve2(k, limit);
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin>>n>>a>>b;
    REP(i, n) cin>>c[i];
    long long ans = 0;
    FOR(i, 1, n) s[i] = c[i] + s[i - 1];
    FORD(k, 62, 0) {
        if (!ok(k, ans))
            ans |= (1ll << k);
    }
    cout<<ans;
}