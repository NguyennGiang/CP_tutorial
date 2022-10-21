#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
vector<int> v[N];
int a[N], dp[N];

int dfs1(int u, int p){
  int ans = 0;
  if (a[u] == 1) ans++;
  else ans--;
  for (int i = 0; i < v[u].size(); i++){
    int next = v[u][i];
    if (next == p) continue;
    int res = dfs1(next, u);
    if (res > 0) ans += res;
  }
  return dp[u] = ans;
}

void dfs2(int u, int p){
  if (p != -1){
    int val = dp[p] - (dp[u] < 0 ? 0: dp[u]);
    dp[u] = dp[u] + (val > 0? val : 0);
  }
  for (int i = 0; i < v[u].size(); i++){
    if (v[u][i] == p) continue;
    dfs2(v[u][i], u);
  }
}

int main(){
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++){
    cin >> a[i];
  }
  
  for (int i = 0; i < n - 1; i++){
    int x, y;
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  dfs1(1, -1);
  dfs2(1, -1);
  
  for (int i = 1; i <= n; i++){
    cout << dp[i] << ' ';
  }
  return 0;
}