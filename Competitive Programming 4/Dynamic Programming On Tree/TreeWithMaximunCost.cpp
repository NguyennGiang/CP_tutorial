/*
  giả sử 2 là con của 1
  thì khoảng cách từ 2->node trong cây con của 2 bằng khoảng cách từ 1 -> (node trong cây con của 2) - 1
  các node khác thì sẽ tăng lên 1;
  
  
  current: kết quả của note 1
  Nếu như có u trong cây con gốc 2
  dist(2, u) = dist(1, u) - 1
  Trong current có chứa dist(1, u) * a[u]
  nếu root là 2, trong current sẽ chứa dist(2, u) * a[u] = (dist(1, u) - 1) * a[u] = dist(1, u) * a[u] - a[u]
  Nếu chuyển từ 1 -> 2
  current sẽ giảm đi a[u] cho mỗi u nằm trong cây con gốc 2
  --
  u không nằm trong cây con gốc 2
  thì current tăng a[u] cho mỗi u khong nằm trong cây con gốc 2
  
  -> với mỗi node u, thì cần biết tổng các a[v] với v là node trong cây con node u; -> sum[u]
  
  dp[v] = dp[u] + x - sum[u] : x tổng a[k] không trong node u;
  --> dp[v] = dp[u] + total - 2 * sum[v] với total = tổng a[i]
  dp[1] += a[i] * d[i];
*/

#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, a[N];
vector<int> g[N];
int d[N];
long long dp[N], sum[N];
long long ans = 0, total;

void dfs(int u, int p = 0){
  d[u] = d[p] + 1;
  sum[u] = a[u];
  for (int i = 0; i < g[u].size(); i++){
    int v = g[u][i];
    if (v == p) continue;
    dfs(v, u);
    sum[u] += sum[v];
  }
}

void dfs2(int u, int p = 0){
  ans = max(ans, dp[u]);
  for (int i = 0; i < g[u].size(); i++){
    int v = g[u][i];
    if (v == p) continue;
    dp[v] = dp[u] + total - 2 * sum[v];
    // cout << v << ' ' << dp[v]  << " " << total << ' '  << sum[u] << endl;
    dfs2(v, u);
  }
}

int main(){
  cin >> n;
  for (int i = 1; i <= n; i++){
    cin >> a[i];
    total += a[i];
  }
  
  for (int i = 1; i < n; i++){
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  d[0] = -1;
  dfs(1);
  // for (int i = 1; i <= n; i++) cout << sum[i] << ' ';
  for (int i = 1; i <= n; i++){
    dp[1] += 1LL * d[i] * a[i];
  }
  // cout << dp[1] ;
  ans = dp[1];
  dfs2(1);
  cout << ans << endl;
  return 0;
}

