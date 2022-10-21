#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

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

bool good(int sum, int a, int b){
  if (!sum) return true;
  if (sum % 10 != a && sum % 10 != b) return false;
  return good(sum / 10, a, b); 
}

int main(){
  int a, b, n; 
  cin >> a >> b >> n;
  
  init();
  int ans = 0;
  for (int i = 0; i <= n; i++){
    int sum = i * a + (n - i) * b;
    if (!good(sum, a, b)) continue;
    //cout << sum << ' ';
    ans = (1LL * ans + 1LL * C(n, i)) % MOD;
  }
  cout << endl << ans; 
  return 0;
}