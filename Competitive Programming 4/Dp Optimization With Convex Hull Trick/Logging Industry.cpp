// dp[i] = min(dp[j] + bj * ai) j = 1...i;

#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 100005;
int n;
int stk[N], cnt;
long long a[N], b[N], d[N];

long long f(ll x, int i) {return x * b[i] + d[i];}
double g(int i, int j) {return (double)(d[j] - d[i]) / (b[i] - b[j]);}

int main(){
    cin >> n;
    int p;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    stk[++cnt] = 1;
    
    for (int i = 2, p = 1; i <= n; i++){
        while(p < cnt && f(a[i], stk[p]) >= f(a[i], stk[p+1])) p++;
        int j = stk[p];
        d[i] = a[i] * b[j] + d[j];
        while(p < cnt && g(i, stk[cnt]) <= g(stk[cnt - 1], stk[cnt])) cnt--;
        stk[++cnt] = i;
    }
    cout << d[n] << endl;
    return 0;
}