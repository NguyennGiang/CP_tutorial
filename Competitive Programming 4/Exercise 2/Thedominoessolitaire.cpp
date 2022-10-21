#include<bits/stdc++.h>
using namespace std;

int n, m;
int f[30], a, b;
int p[30], q[30];
bool ans, vis[30];

void dfs(int i){
  if (ans) return;
  if (i == n + 1){
    if (f[2 * i - 1] == a){
      ans = 1;
    }
    return ;
  }
  
  for (int j = 0; j < m; j++){
    if (p[j] == f[2 * i - 1] && !vis[j]){
      f[2 * i] = p[j];
      f[2 * i + 1] = q[j];
      vis[j] = 1;
      dfs(i + 1);
      vis[j] = 0;
    }
    
    if (q[j] == f[2 * i - 1] && !vis[j]){
      f[2 * i] = q[j];
      f[2 * i + 1] = p[j];
      vis[j] = 1;
      dfs(i + 1);
      vis[j] = 0;
    }
  }
  return ;
}

int main(){
  while(cin >> n && n != 0){
    cin >> m;
    cin >> f[0] >> f[1];
    cin >> a >> b;
    for (int i = 0; i < m; i++){
      cin >> p[i] >> q[i];
    }
    ans = 0;
    memset(vis, 0, sizeof(vis));
    dfs(1);
    cout << (ans ? "YES" : "NO") << endl;
  }
  return 0;
}