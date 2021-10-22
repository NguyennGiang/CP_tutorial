#include <bits/stdc++.h>
using namespace std;

int a[100005], m[100005][17];
int Log[100005];

int query(int l, int r){
    int len = r - l + 1;
    int k = Log[len];
    return max(m[l][k], m[r - (1 << k) + 1][k]);
}

int main(){
    int n; cin >> n;
    Log[1] = 0;
    for (int i = 2; i <= n; i++) Log[i] = Log[i/2] + 1;

    for (int i = 0; i < n; i++){
        cin >> a[i];
        m[i][0] = a[i];
    }

    for (int k = 1; k < 17; k++){
        for (int i = 0; i + (1 << k) <= n; i++){
            m[i][k] = max(m[i][k-1], m[i + (1 << (k-1))][k-1]);
        }
    }

    int m, x, y; cin >> m >> x >> y;
    long long res = 0 ;
    for (int i = 0; i < m; i++){
        res += query(min(x, y), max(x, y));
        x += 7, y += 11;
        if (x >= n - 1) x %= (n - 1);
        if (y >= n) y %= n;
    }
    cout << res;
    return 0;
}