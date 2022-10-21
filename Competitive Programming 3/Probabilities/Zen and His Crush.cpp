#include<bits/stdc++.h>
using namespace std;

double f[1005][1005]; // f[i][j] is the probability, throww i coins and have j heads
double p[1005];

int main(){
    
    // ios_base::sync_with_stdio(NULL);
    // cin.tie(false);

    int t; cin >> t;

    cout << fixed << setprecision(10);
    while(t--){
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++) cin >> p[i];

        f[0][0] = 1.0; // base case f[i][0] = 1;
        for (int i = 1; i <= n; i++){
            f[i][0] = 1;
            for (int j = 0; j <= k; j++){
                f[i][j] = f[i-1][j-1] * p[i] + f[i-1][j] * (1.0 - p[i]);
            }
        }
        cout << f[n][k] << endl;
    }
    return 0;
}