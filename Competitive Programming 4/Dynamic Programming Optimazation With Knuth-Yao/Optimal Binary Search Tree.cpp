#include <bits/stdc++.h>
using namespace std;

const int N = 255;
const int INF = 1e9;
int a[N], pref[N];
int f[N][N], r[N][N];
int n;

int solve(){
    for (int i = 1; i <= n; i++){
        f[i][i] = a[i];
        r[i][i] = i;
        for (int j = i + 1; j <= n; j++){
            f[i][j] = INF;
        }
    }
    for (int i = n - 1;  i >= 1; i--){
        for (int j = i + 1; j <= n; j++){
            for (int k = r[i][j - 1]; k <= r[i+1][j]; k++){
                if (f[i][j] >= f[i][k-1] + f[k+1][j]){
                    f[i][j] = f[i][k-1] + f[k+1][j];
                    r[i][j] = k;
                }
            }
            f[i][j] += pref[j] - pref[i-1];
        }
    }
    return f[1][n];
}

int main(){
    while(cin >> n){
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            pref[i] = pref[i-1] + a[i];
        }
        cout << solve() - pref[n] + pref[0]<< endl;
    }
}