#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll x, y;
int a[300], tot;
int f[30][30][2];
int num[30];

long long dp(int pos, int st, int state, int lead, int flag){
    if (pos == 0) return state;
    if (f[pos][st][state] != -1 && lead && flag) return f[pos][st][state];
    ll ans = 0;
    int x = flag ? 9 : a[pos];
    for (int i = 0; i <= x; i++){
        num[pos] = i;
        if (!lead){
            ans += dp(pos - 1, i == 0 ? st : pos, state, lead || i > 0, flag || (i < x));
        } else {
            if (pos <= st / 2 && state) ans += dp(pos - 1, st, state && (i == num[st - pos + 1]), lead, flag || (i < x));
            else ans += dp(pos - 1, st, state, lead, flag || (i < x));
        }
    }
    if (lead && flag) f[pos][st][state] = ans;
    return ans;
}

long long solve(ll x){
    if (x < 0) return 0;
    if (x == 0) return 1;
    tot = 0;
    while(x) a[++tot] = x % 10, x /= 10;
    return dp(tot, 0, 1, 0, 0);
}

int main(int argc, char const *argv[])
{
    memset(f, -1, sizeof(f));
    int t; cin >> t;
    for (int i = 1; i <= t; i++){
        ll a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        cout << "Case " << i << ": " << solve(b) - solve(a - 1) << endl;
    }
    return 0;
}