#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1e9;
const int N = 1e5 + 5;
int n, k, s;

struct Matrix {
  vector<vector<ll>> a;
  int n, m;
  
  Matrix(int n = 0, int m = 0): n(n), m(m){
    a.resize(n);
    for (int i = 0; i < n; i++){
      a[i].resize(m);
      for (int j = 0; j < m; j++){
        a[i][j] = 0;
      }
    }
  }
};

Matrix operator*(const Matrix& a, const Matrix& b){
  Matrix c (a.n, b.m);
  
  for (int i = 0; i < a.n; i++){
    for (int j = 0; j < b.m; j++){
      for (int k = 0; k < a.m; k++){
        c.a[i][j] += (a.a[i][k] * b.a[k][j]) % MOD;
        c.a[i][j] %= MOD;
      }
    }
  }
  return c;
}

Matrix Iden(int n){
  Matrix mat(n, n);
  for (int i = 0; i < n; i++){
    mat.a[i][i] = 1;
  }
  return mat;
}

Matrix pow(const Matrix& a, ll k){
  if (k == 0) return Iden(a.n);
  if (k == 1) return a;
  Matrix tmp = pow(a, k / 2);
  tmp = tmp * tmp;
  if (k & 1) tmp = tmp * a;
  return tmp;
}

ll a[N];
int f[N][20];

int binary(int i){
  int l = 1, r = i;
  int ans = -1;
  while(l <= r){
    int m = (l + r) / 2;
    ll sum = a[i] - a[m-1];
    if (sum <= 1LL * s){
      ans = m;
      r = m - 1;
    }
    else l = m + 1;
  }
  return ans;
}

int get(int i, int k){
  for (int j = 19; j >= 0 && i > 0; j--){
    if ((1 << j) <= k){
      i = f[i][j] - 1;
      k -= 1 << j;
    }
  }
  return i + 1;
}

void solve(){
  cin >> n >> k >> s;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
  
  for (int i = 1; i <= n; i++){
    a[i] += a[i-1];
  }
  
  for(int i = 1; i <= n; i++){
    f[i][0] = binary(i);
  }
  
  for (int j = 1; j < 20; j++){
    for (int i = 1; i <= n; i++){
      if (f[i][j-1] == 1) {
        f[i][j] = 1;
        continue;
      }
      f[i][j] = f[f[i][j - 1] - 1][j-1];
    }
  }
  
  int ans = 0;
  for (int i = 1; i <= n; i++){
    int tmp = i - get(i, k) + 1;
    if (tmp > ans){
      ans = tmp;
    }
  }
  cout << ans << endl;

}

int main(){
  int t;
  cin >> t;
  while(t--){
    solve();
  }
  return 0;
}