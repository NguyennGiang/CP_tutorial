#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef pair <int, int> pii;

const int N = 1e5 + 5;
int n, counter;
vector <int> v[N];
int bit[N], st[N], en[N], w[N],  q1[N], q2[N];
pii E[N];
int ans[N];

void dfs(int u, int fa){
  st[u] = ++counter;
  for (int e : v[u]){
    if (e != fa) dfs(e, u);
  }
  en[u] = counter;
}

int get(int x){
  int sum = 0;
  while (x > 0){
    sum ^= bit[x];
    x -= x & -x;
  }
  return sum;
}

void add(int x, int val){
  while (x <= n){
    bit[x] ^= val;
    x += x & -x;
  }
}

int main(){
  int t;
  cin >> t;
  while(t--){
    cin >> n;
    counter = 0;
    for (int i = 0; i <= n; i++){
      bit[i] = 0;
      v[i].clear();
    }
    for (int a, b, c,  i = 1; i < n; i++){
      cin >> a >> b >> c;
      v[a].push_back(b);
      v[b].push_back(a);
      E[i] = {a, b};
      w[i] = c;
    }
    dfs(1, -1);
    vector <pii> edge;
    int q; cin >> q;
    for (int a, b, c, i = 1; i <= q; i++){
      cin >> a >> b >> c;
      q1[i] = a, q2[i] = b;
      edge.push_back({c, i});
    }
    for (int i = 1; i < n; i++){
      if (st[E[i].f] < st[E[i].s]){
        swap(E[i].f, E[i].s);
      }
      edge.push_back({w[i], -E[i].f});
    }
    sort(edge.begin(), edge.end());
    for (pii Q : edge){
      if (Q.s >= 0){
        int id = Q.s;
        ans[id] = get(st[q1[id]]) ^ get(st[q2[id]]);
      }
       else {
         int id = -Q.s;
         add(st[id], Q.f);
         add(en[id] + 1, Q.f);
       }
    }
    for (int i = 1; i <= q; i++){
      cout << ans[i] << '\n';
    }
  }
  return 0;
}