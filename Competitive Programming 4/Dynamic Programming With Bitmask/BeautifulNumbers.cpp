#include<bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
long long f[105][1 << 11][11];

int main(){
  int t;
  cin >> t;
  while(t--){
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i <= m; i++){
      for (int j = 0; j < (1 << n); j++){
        for (int k = 0; k < n; k++){
          f[i][j][k] = 0;
        }
      }
    }
    
    for (int i = 1; i < n; i++){
      f[1][1 << i][i] = 1;
    }
          
    for (int i = 2; i <= m; i++){
      for (int j = 0; j < (1 << n); j++){
        for (int k = 0; k < n; k++){
          if (k - 1 >= 0 && (j >> (k - 1)) & 1){
            f[i][j | (1 << k)][k] = (f[i][j][k] + f[i-1][j][k-1]) % MOD;
          }
          if (k + 1 < n && (j >> (k + 1)) & 1){
            f[i][j | (1 << k)][k] = (f[i][j][k] + f[i-1][j][k + 1]) % MOD;
          }
        }
      }
    }
    
    long long ans = 0;
    for (int i = 1; i <= m; i++){
      for (int j = 0; j < n; j++){
        ans = (ans + f[i][(1 << n) - 1][j]) % MOD;
      }
    }
    cout << ans << endl;
  }
  return 0;
}

