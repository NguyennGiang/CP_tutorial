#include <bits/stdc++.h>
using namespace std;

const int N = 505;

struct Node
{
    int x, y, t;
    bool operator <(const Node &a){
        return t < a.t;
    }
} a[N * N];

int mp[N][N];
int sum[N][N];
int n, m, k, q;

bool solve(int time){
    memset(mp, 0, sizeof(mp));
    memset(sum, 0, sizeof(sum));

    for (int i = 0; i < q; i++){
        if (a[i].t <= time){
            mp[a[i].x][a[i].y] = 1;
        }
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + mp[i][j];
        }
    }

    for (int i = k; i <= n; i++){
        for (int j = k; j <= m; j++){
            int tmp = sum[i][j] - sum[i-k][j] - sum[i][j-k] + sum[i-k][j-k];
            if (tmp == k * k){
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    cin >> n >> m >> k >> q;
    for (int i = 0; i < q; i++){
        cin >> a[i].x >> a[i].y >> a[i].t;
    }

    sort(a, a + q);
    int ans = INT_MAX;
    int l = 0, r = q - 1;
    while(l <= r){
        int m = (l + r) / 2;
        if (solve(a[m].t)){
            ans = a[m].t;
            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }
    if (ans == INT_MAX){
        ans = -1;
    }
    cout << ans << endl;
    return 0;
}