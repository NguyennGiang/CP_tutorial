#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second

const int N = 3e5 + 5;
const int mod = 998244353;
int n;
pair<int, int> a[N];
long long fac[N];

bool cmp(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}

int main(){
    cin >> n;
    fac[0] = 1;
    for (int i = 1; i <= n; i++){
        cin >> a[i].fi >> a[i].se;
        fac[i] = 1LL * fac[i-1] * i % mod;
    }

    sort(a + 1, a + 1 + n);

    long long tmp1 = 1;
    long long tmp2 = 1;
    long long tmp3 = 1;

    for (int i = 1; i <= n; i++){
        int cnt = 1;
        int j = i + 1;
        while (j <= n && a[i].fi == a[j].fi) cnt++, j++;
        tmp1 = 1LL * tmp1 * fac[cnt] % mod;
        i = j - 1;
    }

    for (int i = 1; i <= n; i++){
        int cnt = 1;
        int j = i + 1;
        while(j <= n && a[i].fi == a[j].fi && a[i].se == a[j].se) cnt++, j++;
        tmp3 = 1LL * tmp3 * fac[cnt] % mod;
        i = j - 1;
    }
    for (int i = 1; i < n; i++){
        if (a[i].se > a[i + 1].se) tmp3 = 0;
    }

    sort(a + 1, a + 1 + n, cmp);
    for (int i = 1; i <= n; i++){
        int cnt = 1;
        int j = i + 1;
        while (j <= n && a[i].se == a[j].se) cnt++, j++;
        tmp2 = 1LL * tmp2 * fac[cnt] % mod;
        i = j - 1;
    }

    cout << (fac[n] - tmp1 - tmp2 + tmp3 + 2 * mod) % mod << endl;
    return 0;
}