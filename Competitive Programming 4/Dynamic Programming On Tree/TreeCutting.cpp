/*
  2 màu : xanh và đỏ
  red = tổng số node màu dỏ;
  blue = tổng số node màu xanh;
  red[u] số lượng màu đỏ trong node u;
  blue[u] số lượng màu xanh trong node u;
  
  đỉnh v là con của u; 
  nếu mà red[v] = 0 && blue[v] = blue -> u, v sẽ là cạnh đẹp;
  hoặc nếu red[v] = red && blue[v] = 0 -> u, v cũng là cạnh đẹp;
  dfs() 1 lần tính red[u], blue[u];
*/ 

#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;
int n;
int red, blue;
int color[N];
int num[N][2]; // num[0] : red, num[1] : blue;
vector<int> g[N];
int ans;

void dfs(int u, int par = 0){
  if (color[u] == 1) num[u][0]++;
  else if (color[u] == 2) num[u][1]++;
  for (int i = 0; i < g[u].size(); i++){
    int v = g[u][i];
    if (v == par) continue;
    dfs(v, u);
    num[u][0] += num[v][0];
    num[u][1] += num[v][1];
  }
  if (num[u][0] == red && num[u][1] == 0) ans++;
  else if(num[u][0] == 0 && num[u][1] == blue) ans++;
}

int main(){
  cin >> n;
  for (int i = 1; i <= n; i++){
    int x;
    cin >> x;
    color[i] = x;
    if (x == 1) red++;
    else if (x == 2) blue++;
  }
  for (int i = 1; i < n; i++){
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(1);
  cout << ans << endl;
  return 0;
}
