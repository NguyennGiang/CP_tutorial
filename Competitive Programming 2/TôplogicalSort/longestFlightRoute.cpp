#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
const int maxn = 1e5 + 10;
int n, m;
vector <int> graph[maxn];
int indegree[maxn];
vector <int> result;
int dist[maxn], pre[maxn];

int main(){
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++){
    int u, v;
    scanf("%d %d", &u, &v);
    graph[u].push_back(v);
    indegree[v]++;
  }
  
  for (int i = 1; i <= n; i++){
    dist[i] = - maxn;
  }
  queue <int> q;
  dist[1] = 0;

  for (int i = 1; i < n; i++){
    if(indegree[i] == 0){
      q.push(i);
    }
  }

  while(!q.empty()){
    int u = q.front();
    q.pop();

    for (int v : graph[u]){
      if (dist[v] < dist[u] + 1){
        dist[v] = dist[u] + 1;
        pre[v] = u;
      }
      indegree[v] --;
      if(indegree[v] == 0) q.push(v);
    }
  }

  if (dist[n] < 0){
    cout << "IMPOSSIBLE\n";
  }
  else {
    result.push_back(n);
    while (result.back() != 1){
      result.push_back(pre[result.back()]);
    }
    reverse(result.begin(), result.end());

    cout << result.size() << '\n';

    for (int u : result) cout << u << " ";
  }
  return 0;
}
