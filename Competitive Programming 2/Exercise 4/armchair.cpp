#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
int f[N][N], a[N], pos[N];
int n, cnt = 0;

int main(){
    memset(f, 0x3f, sizeof(f));
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        if (a[i]) pos[++cnt] = i;
    }

    for (int i = 0; i <= n; i++) f[0][i] = 0;

    for (int i = 1; i <= cnt; i++){
        for (int j = 1; j <= n; j++){
            f[i][j] = f[i][j-1];
            if (!a[j]) {
                f[i][j] = min(f[i][j-1], f[i-1][j-1] + abs(j - pos[i]));
            }
        }
    }
    cout << f[cnt][n] << endl;
    return 0;
}