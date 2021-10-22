#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int Log[N], C[N][20], D[N][20];
int n, k;

bool Query(int l, int r){
    int len = Log[r - l + 1];
    int x = max(C[l][len], C[r - (1 << len) + 1][len]);
    int y = max(D[l][len], D[r - (1 << len) + 1][len]);
    int dis = abs(x - y);
    return dis <= k;
}

void build(){
    Log[1] = 0;
    for (int i = 2; i <= n; i++){
        Log[i] = Log[i / 2] + 1;
    }

    for (int i = 0; i < n; i++) cin >> C[i][0];
    for (int i = 0; i < n; i++) cin >> D[i][0];

    for (int k = 1; k < 17; k++){
        for (int i = 0; i + (1 << k) <= n; i++){
            C[i][k] = max(C[i][k-1], C[i + (1 << (k-1))][k-1]);
            D[i][k] = max(D[i][k-1], D[i + (1 << (k-1))][k-1]);
        }
    }
}

int main(){
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++){
        cin >> n >> k;
        build();
        long long ans = 0;
        int r = n - 1;
        for (int l = 0; l < n; l++){
            while (Query(l , r) && r >= 0){
                r--;
            }
            ans += abs(n - r);
        }
        cout << "Case #" << tc << ": " << ans << endl;
    }
    return 0;
}

// Time O(N * N * T)