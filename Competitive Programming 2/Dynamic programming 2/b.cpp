#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int n, m;
int f[N][N];

int main(){
  cin >> n >> m;
  vector <int> a(n), b(m);
  for (int &ai : a) cin >> ai;
  for (int &bi : b) cin >> bi;
  
  // n = 1;
  for (int i = 1; i <= m; i++){
    f[1][i] = (a[0] == b[i-1] ? 1 : f[1][i-1]);
  }
  
  // m = 1;
  for (int j = 1; j <= n; j++){
    f[j][1] = (a[j-1] == b[0] ? 1 : f[j-1][1]);
  }
  
  for (int i = 2; i <= n; i++){
    for (int j = 2; j <= m; j++){
      if (a[i-1] == b[j-1]){
        f[i][j] = f[i-2][j-2] + 1;
      }
      else {
        f[i][j] = max(f[i-1][j], f[i][j-1]);
      }
    }
  }
  cout << f[n][m];
  return 0;
}