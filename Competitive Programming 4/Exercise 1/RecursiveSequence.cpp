#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1e9;

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

void solve(){
  int k; cin >> k;
  
  Matrix mat(k, k);
  for (int i = 1; i < k; i++){
    mat.a[i-1][i] = 1;
  }
  
  Matrix base(k, 1);
  for (int i = 0; i < k; i++){
    cin >> base.a[i][0];
  }
  
  for (int i = k - 1; i >= 0; i--){
    cin >> mat.a[k-1][i];
  }
  
  int n; cin >> n;
  if (n < k){
    cout << base.a[n-1][0] << endl;
    return;
  }
  mat = pow(mat, n - 1);
  mat = mat * base;
  cout << mat.a[0][0] << endl;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    solve();
  }
  return 0;
}