#include <bits/stdc++.h>

using namespace std;

int checkBit(int n){
    int cnt = 0;
    for (int i = 0; i < sizeof(int) * 8; i++){
        if (n & (1 << i)){
            cnt++;
        }
    }
    return cnt;
}

int main() {
    int n, l, r, x;
    cin >> n >> l >> r >> x;

    vector <int> v(n);
    for (int &vi : v) cin >> vi;

    int ans = 0;

    for (int i = 0; i < (1 << n); i++){
        
        int xx = -1;
        int nn = 1000005;
        int sum = 0;

        if(checkBit(i) < 1){
            continue;
        }

        for (int j = 0; j < n; j++){
            if (i & (1 << j)){
                sum += v[j];
                xx = max(xx, v[j]);
                nn = min(nn, v[j]);
            }
        }

        if (l <= sum && sum <= r && (xx - nn) >= x){
            ans++;
        }
    }
    cout << ans;
    return 0;
}