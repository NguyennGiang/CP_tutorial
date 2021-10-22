#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int a[N], d[N], st[N][20], lg[N];

int Q(int l, int r){
    int k = lg[r - l + 1];
    return max(st[l][k], st[r - (1 << k) + 1][k]);
}

int main(){
    lg[1] = 0;
    for (int i = 2; i < N; i++) lg[i] = lg[i/2] + 1;
    int q, n;
    while (cin >> n && n != 0){
        cin >> q;
        for (int i = 1; i <= n; i++) cin >> a[i];
        d[1] = 1;
        for (int i = 2; i <= n; i++){
            if (a[i] == a[i-1]) d[i] = d[i-1] + 1;
            else d[i] = 1;
        }
        for (int i = 1; i <= n; i++) st[i][0] = d[i];

        for (int j = 1; j < 17; j++){
            for (int i = 1; i + (1 << j) - 1 <= n; i++){
                st[i][j] = max(st[i][j-1], st[i + (1 << (j - 1))][j-1]);
            }
        }
        int l, r;
        int ans;
        while (q--){
            cin >> l >> r;
            if (a[l] == a[r]) ans = r - l + 1;
            else {
                int x = upper_bound(a + l, a + r + 1, a[l]) - a;
                ans = x - l;
                l = x;
                x = lower_bound(a + l, a + r + 1, a[r]) - a;
                ans = max(ans, r - x + 1);
                r = x - 1;
                if (r >= l) ans = max(ans, Q(l, r));
            }
            cout << ans << endl;
        }
    }
    return 0;
}

// Time O(T * (nlogn  + qlogn)) 
// T : numbes of testcase