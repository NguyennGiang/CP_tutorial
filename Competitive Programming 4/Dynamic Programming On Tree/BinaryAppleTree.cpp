#include<bits/stdc++.h>
using namespace std;

struct Node {
  int y, val;
};
const int N = 110;
vector<Node> v[N];
int sz[N], n, m, num;
int dp[N][N];

void dfs(int u, int p){
  num++;
  sz[u] = 1;
  for (int i = 0; i < v[u].size(); i++){
    int y = v[u][i].y;
    if (y == p) continue;
    dfs(y, u);
    sz[u] += sz[y];
  }
} 

void dfs2(int u, int p){
  for (int i = 0; i < v[u].size(); i++){
    int y = v[u][i].y;
    int val = v[u][i].val;
    if (y == p) continue;
    dfs2(y, u);
    for (int j = sz[u]; j > 1; j--){
      for (int k = 1; k < j; k++){
        dp[u][j] = max(dp[u][j], dp[u][j-k] + dp[y][k] + val);
      }
    }
  }
}

int main(){
  while(cin >> n >> m){
    num = 0;
    int x, y, z;
    memset(sz, 0, sizeof(sz));
    for (int i = 1; i < n; i++){
      cin >> x >> y >> z;
      v[x].push_back({y, z});
      v[y].push_back({x, z});
    }
    memset(dp, 0, sizeof(dp));
    dfs(1, -1);
    dfs2(1, -1);
    cout << dp[1][m+1];
  }
  return 0;
}