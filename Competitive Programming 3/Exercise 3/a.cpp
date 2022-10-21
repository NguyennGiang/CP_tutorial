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

int main(){
  init();
  
  int t;
  cin >> t;
  while(t--){
    int n; cin >> n;
    if (n == 0) cout << 1 << endl;
    else cout << 0 << endl;
  }
  return 0;
}