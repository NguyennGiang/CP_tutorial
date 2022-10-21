#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--){
        int n, m;
        cin >> n >> m;
        m ++;
        int ans = 0;
        for (int k = 30; k >= 0 && n < m; k--){
            if ((n >> k & 1) == (m >> k & 1)) continue;
            if (m >> k & 1) ans |= 1 << k, n |= 1 << k;
        }
        cout << ans << endl;
    }
    return 0;
}

/*
    Find n ^ k <= m;
    if k is present in the sequence, then there must be some x, 0 <= x <= m, and ^ x = k;
    --> check if  n ^ k <= m;
    if (ni == mi) we can choose ki = 0;
    if (ni == 1, mi == 0) we must break, no choose k & n > m + 1;
    if (ni == 0, mi == 1) we must choose ki = 1;
*/