#include <bits/stdc++.h>
using namespace std;

const int N = 3000;
int n;
int a[N], f[N][N], p[N][N];

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        p[i][i] = i;
        a[i] += a[i-1];
    }

    for (int j = 2; j <= n; j++){
        for(int i = j - 1; i > 0; i--){
            for (int k = p[i][j-1]; k <= p[i+1][j]; k++){
                long long ans = min(f[i][k] + a[k] - a[i-1], f[k+1][j] + a[j] - a[k]);
                if (f[i][j] < ans){
                    f[i][j] = ans;
                    p[i][j] = k;
                }
            }
        }
    }
    cout << f[1][n];
    return 0;
}