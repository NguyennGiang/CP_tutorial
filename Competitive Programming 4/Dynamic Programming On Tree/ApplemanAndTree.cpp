#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define N 100005

vector<int> g[N];
long long dp[N][2];
int n, color[N];

void dfs(int x, int p = -1){
  if (color[x] == 1) dp[x][1] = 1;
  else dp[x][0] = 1;
  for (int i = 0, y; i < g[x].size(); i++){
    if (y == p) continue;
    y = g[x][i];
    dfs(y);
    dp[x][1] = ((dp[x][1] * (dp[y][1] + dp[y][0]) % MOD) + (dp[x][0] * dp[y][1])) % MOD;
    dp[x][0] = (dp[x][0] * (dp[y][0] + dp[y][1])) % MOD;
  }
}

int main(){
  int x;
  cin >> n;
  for (int i = 1; i< n; i++){
    cin >> x;
    g[x].push_back(i);
  }
  for (int i = 0; i < n; i++){
    cin >> color[i];
  }
  
  dfs(0);
  cout << dp[0][1] << endl;
  return 0;
}