#include <bits/stdc++.h>
using namespace std;

const int N = 36;
long long dp[N][N];

int main(){
  int n, h;
  cin >> n >> h;
  dp[0][0] = 1;
  // trái: k-1
  // phải: i - k
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= n; j++){
      for (int k = 1; k <= i; k++){ // k : root
        long long tmp = 0;
        long long l = 0; // sô cây bên trai có chiều cao nhỏ hơn j - 1;
        for (int t = 0; t < j; t++){
          l += dp[k - 1][t];
        }
        tmp += l * dp[i-k][j-1]; 
        long long r = 0; // so cay ben phai co chieu cao nho hon hoac bang j - 1;
        for (int t = 0; t < j; t++){
          r += dp[i-k][t];
        }
        tmp += r * dp[k-1][j-1];
        tmp -= dp[k-1][j-1] * dp[i-k][j-1];
        dp[i][j] += tmp;
      }
    }
  }
  long long res = 0;
  for (int i = h; i <= n; i++){
    res += dp[n][i];
  }  
  cout << res;
  return 0;
}