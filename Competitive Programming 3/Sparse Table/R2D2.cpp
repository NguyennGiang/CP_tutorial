#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
int ans[10], a[N][6], st[6][N][20];
int n, m, s;
int lg[N] = {-1};

int main(){
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++){
        lg[i] = lg[i/2] + 1;
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
            st[j][i][0] = a[i][j];
        }
    }

    for (int k = 1; k <= m; k++){
        for (int i = 1; i < 17; i++){
            for (int j = 1; j + (1 << i) - 1 <= n; j++){
                st[k][j][i] = max(st[k][j][i-1], st[k][j + (1 << (i - 1))][i-1]);
            }
        }
    }

    int l = 1, r = 1;
    int cn[10];
    while (r <= n){
        ll cnt = 0;
        int len = lg[r - l + 1];
        for (int i = 1; i <= m; i++){
            cn[i] = max(st[i][l][len], st[i][r - (1 << len) + 1][len]);
            cnt += cn[i];
        }

        if (cnt <= s){
            r++;
            for (int i = 1; i <= m; i++){
                ans[i] = cn[i];
            }
        }
        else {
            l++, r++;
        }
    }

    for (int i = 1; i <= m; i++){
        cout << ans[i] << " ";
    }
    return 0;
}

// Time O(m * nlogn)