#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MOD = 1e9 + 9;

struct Matrix {
  vector<vector<ll>> a;
  int n, m;
  Matrix(int n = 0, int m = 0) : n(n), m(m){
    a.resize(n);
    for (int i = 0; i < n; i++){
      a[i].resize(m);
      for (int j = 0; j < m; j++){
        a[i][j] = 0;
      }
    }
  }
};

Matrix operator * (const Matrix& a, const Matrix& b){
  Matrix c(a.n, b.m);
  for (int i = 0; i < a.n; i++){
    for (int j = 0; j < b.m; j++){
      for (int k = 0; k < a.n; k++){
        c.a[i][j] += a.a[i][k] * b.a[k][j] % MOD;
        c.a[i][j] %= MOD;
      }
    }
  } 
  return c;
}

Matrix Indentity(int n){
  Matrix mat(n, n);
  for (int i = 0; i < n; i++) mat.a[i][i] = 1;
  return mat;
}

Matrix pow(const Matrix& a, ll p){
  if(p == 0) return Indentity(a.n);
  if(p == 1) return a;
  Matrix c = pow(a, p /2);
  c = c * c;
  if (p & 1){
    c = c * a;
  }
  return c;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifdef ONLINEJUDGE
        clock_t tStart = clock();
        freopen("input.txt","r",stdin); 
        freopen("output.txt","w",stdout); 
    #endif

    // Code below
    Matrix mat(3, 3), base(3, 1), tmp;
    mat.a[0][1] = mat.a[1][2] = mat.a[2][0] = mat.a[2][1] = mat.a[2][2] = 1;
    base.a[1][0] = 1; base.a[2][0] = 2;
  
    ll n;
    while(cin >> n && n != 0){
        n--;
        tmp = pow(mat, n);
        tmp = tmp * base;
        cout << tmp.a[0][0] << '\n';
    }
   return 0;
}