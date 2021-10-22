#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second

int a[50005], Log[50005];
pair <int, int> m[50005][17];

int query(int l, int r){
    int len = r - l + 1;
    int k = Log[len];
    int x = min(m[l][k].f, m[r - (1 << k) + 1][k].f);
    int y = max(m[l][k].s, m[r - (1 << k) + 1][k].s);
    //cout << x << " " << y << endl;
    return y - x;
}

int main(){
    int n, q; cin >> n >> q;
    Log[1] = 0;
    for (int i = 2; i <= n; i++) Log[i] = Log[i/2] + 1;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        m[i][0].f = m[i][0].s = a[i];
    }
    for (int k = 1; k < 17; k++){
        for (int i = 0; i + (1 << k) <= n; i++){
            m[i][k].f = min(m[i][k-1].f, m[i + (1 << (k - 1))][k-1].f);
            m[i][k].s = max(m[i][k-1].s, m[i + (1 << (k - 1))][k-1].s);
        }
    }
    int x, y;
    while (q--){
        cin >> x >> y;
        x--, y--;
        cout << query(x, y) << endl;
    }
    return 0;
}

// Time O(q + nlogn);