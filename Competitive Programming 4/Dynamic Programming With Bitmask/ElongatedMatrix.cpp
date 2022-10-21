#include<bits/stdc++.h>
using namespace std;

int a[20][10000 + 5], dis[20][20], nex[20][20];
int f[1 << 18][20];

int main(){
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      cin >> a[i][j];
    }
  }
  
  if (n == 1){
    int ans = 1e9;
    for (int i = 0; i + 1< m; i++){
      ans = min(ans, abs(a[0][i] - a[0][i+1]));
    }
    cout << ans;
    return 0;
  }
  
  for (int i = 0; i < n; i++){
    for (int j = i + 1; j < n; j++){
      int m1 = 1e9, m2 = 1e9, m3 = 1e9;
      for (int k = 0; k < m; k++){
        m1 = min(m1, abs(a[i][k] - a[j][k]));
        if (k >= 1){
          m2 = min(m2, abs(a[i][k-1] - a[j][k]));
          m3 = min(m3, abs(a[j][k-1] - a[i][k]));
        }
      }
      nex[i][j] = m2;
      nex[j][i] = m3;
      dis[i][j] = dis[j][i] = m1;
    }
  }
  
  int ans = 0;
  for (int i = 0; i < n; i++){
    memset(f, -1, sizeof(f));
    f[1 << i][i] = 1e9;
    for (int s = 0; s < (1 << n); s++){
      for (int st = 0; st < n; st++){
        if (f[s][st] != -1){
          for (int nx = 0; nx < n; nx++){
            if (((s >> nx) & 1) == 0){
              f[s|(1 << nx)][nx] = max(f[s|(1 << nx)][nx], min(f[s][st], dis[st][nx]));
            }
          }
        }
      }
    }
    for(int k = 0; k < n; k++){
      ans = max(ans, min(f[(1 << n) - 1][k], nex[k][i]));
    }
  }
  cout << ans;
}