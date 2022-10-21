#include<bits/stdc++.h>
using namespace std;

const int N = 10000000 + 5;
const int M = 1000 + 5;
int n, m;
long long a[M], sum[M];
long long f[M][M], p[M][M];

int main(){
  while(cin >> n >> m){
    for (int i = 1; i <= m; i++){
      cin >> a[i];
      sum[i] = sum[i-1] + a[i] - a[i-1];
    }
    sum[++m] = sum[m - 1] + n - a[m - 1]; 
    
    for (int i = 1; i <= m; i++) {
      p[i][i] = i;
    }
    
    for (int i = m - 1; i >= 1; i--){
      for (int j = i + 1; j <= m; j++){
        f[i][j] = 1e18;
        for (int k = p[i][j-1]; k <= p[i+1][j]; k++){
          long long tmp = f[i][k] + f[k+1][j];
          if (f[i][j] > tmp){
            f[i][j] = tmp;
            p[i][j] = k;
          }
        }
        f[i][j] += sum[j] - sum[i-1];
      }
    }
    cout << f[1][m] << endl;
  }
  return 0;
}