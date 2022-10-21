#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int N = 5e5 + 5;

int p[N], inv[N];
int pw1[N], pw2[N];

int qp(int a, int b){
  if (b == 0) return 1;
  if (b & 1){
    return 1LL * a * qp(a, b - 1) % MOD;
  }
  int x = qp(a, b >> 1);
  return 1LL * x * x % MOD;
}

void init(){
  p[0] = 1;
  inv[0] = 1;
  for (int i = 1; i < N; i++){
    p[i] = 1LL * p[i-1] * i % MOD;  
    inv[i] = qp(p[i], MOD - 2);
  }
}

int C(int a, int b){
  return (1LL * p[a] * inv[a - b] % MOD * inv[b]) % MOD;
}
int main(){
  int t; cin >> t;
  init();
  
  while(t--){
    int n, m;
    cin >> m >> n;
    int ans = 0;
    
    pw1[0] = 1;
    for (int i = 1; i <= m; i++){
      pw1[i] = 1LL * pw1[i-1] * (n - 1) % MOD;
    }
    pw2[0] = 1;
    for (int i = 1; i <= m; i++){
      pw2[i] = 1LL * pw2[i-1] * n % MOD;
    }
    for (int i = n; i <= m; i++){
      ans = (ans + 1LL * C(i-1, n-1) * pw1[i-n] % MOD * pw2[m - i] % MOD) % MOD;
      //cout << ans << endl;
    }
    cout << ans << endl;
  }
  return 0;
}