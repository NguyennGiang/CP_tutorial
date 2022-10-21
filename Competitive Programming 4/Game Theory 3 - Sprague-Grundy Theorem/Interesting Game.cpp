#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, dp[N], mex[N];

int main(){
  cin >> n;
  int ans = -1;
  int cnt = 1;
  for (int i = 3; i <= n; i++){
    for (int m = 2; ; m++){
      int r = i - m * (m + 1) / 2;
      if (r < 0) break;
      if (r % m ) continue;
      int g = 0;
      for (int j = 1; j <= m; j++){
        g ^= dp[r/m + j];
      }
      if (!g && i == n && ans < 0) ans = m;
      mex[g] = cnt;
    }
    for (int j = 0; ; j++){
      if (mex[j] != cnt){
        dp[i] = j;
        cnt++;
        break;
      }
    }
  }  
  cout << ans;
}