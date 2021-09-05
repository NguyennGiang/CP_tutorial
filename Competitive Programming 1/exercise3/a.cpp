#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;
vector <vector <int>> v;
vector <bool> used;
typedef pair <int, int> pii;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  int t; 
  cin >> t; 
  
  for (int tc = 1; tc <= t; tc++){
    int n; 
    cin >> n;
    
    v.assign(20007, vector <int>());
    used.assign(20007, 1);
    
    for (int i = 0; i < n; i++){
      int a, b; 
      cin >> a >> b;
      v[a].push_back(b);
      v[b].push_back(a);
      used[a] = used[b] = 0;
    }
    
    int ans = 0;


    
    //bfs - create a bipartite graph (if current note is 0, so next note should be 1 and vice verse).
    
    queue <pii> q;
    
    for (int i = 1; i < 20007; i++){
      if (!used[i]) {
        int cnt[2] = {0, 0};
        q.push({i, 1});
        used[i] = 1;
        while(!q.empty()){
          pii u = q.front();
          q.pop();
          cnt[u.se]++;
          for (int adj : v[u.fi]){
            if (!used[adj]){
              int x = 1 - u.se;
              used[adj] = 1;
              q.push({adj, x});
            }
          }
         
        }
        
        ans += max(cnt[0], cnt[1]);
      }
    }
    
    cout << "Case " << tc << ": " << ans << '\n';
  }
  return 0;
}