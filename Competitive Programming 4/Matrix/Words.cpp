#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MOD = 1e9 + 7;

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

ostream& operator<<(ostream& os, const Matrix a){
    for (int i = 0; i < a.n; i++){
        for (int j = 0; j < a.m; j++){
            os << a.a[i][j] << ' ';
        }
        os << '\n';
    }
    return os;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // #ifdef ONLINEJUDGE
    //     clock_t tStart = clock();
    //     freopen("input.txt","r",stdin); 
    //     freopen("output.txt","w",stdout); 
    // #endif

    // Code below
    ll n; cin >> n;
    if (n == 1){
        cout << 2 << endl;
    }
    else if (n == 2) {
        cout << 3 << endl;
    }
    else {
        Matrix a(3, 1), b(1, 3), m(3, 3);

        a.a[0][0] = 1;
        a.a[1][0] = 2;
        a.a[2][0] = 3;
        cout << a << endl;

        m.a[0][1] = 1;
        m.a[1][2] = 1;
        m.a[2][0] = 1;
        m.a[2][2] = 1;
        cout << m << endl;
        m = pow(m, n);
        cout << m << endl;
        a = m * a;
        cout << a << endl;
        cout << a.a[0][0];
    }

    #ifdef ONLINEJUDGE
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC); 
    #endif
    return 0;
}