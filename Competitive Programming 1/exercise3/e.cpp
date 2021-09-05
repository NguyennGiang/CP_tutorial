#include<bits/stdc++.h>
#define Pair pair<LL, int> 
#define MP make_pair
#define fi first
#define se second 
#define LL  long long
using namespace std;
const int MAXN = 2e5 + 10;
const LL INF = 1e18 + 10; 
const LL mod1 = 2860486313LL; 

int N, M, S, T, vis[MAXN];
LL f[MAXN], g[MAXN];
LL dis[MAXN], rdis[MAXN];
vector<Pair> v[MAXN], t[MAXN];
struct Edge { int u, v; LL w;} E[MAXN];


void Dij(int S, LL *d, LL *f, int opt) {
    priority_queue<Pair> q; 
    q.push(MP(0, S));
    
    for(int i = 1; i <= N; i++) d[i] = INF;
    
    d[S] = 0; 
    f[S] = 1; 
    memset(vis, 0, sizeof(vis)); 
    
    while(!q.empty()) {
        if(vis[q.top().se]) {
            q.pop(); 
            continue;
        }
        int p = q.top().se; 
        q.pop(); 
        vis[p] = 1;
        
        vector<Pair> *e = (opt == 1 ? v + p : t + p);
        
        for(int i = 0; i < e -> size(); i++) {
            int to = (*e)[i].fi, w = (*e)[i].se;
            if(d[to] > d[p] + w) d[to] = d[p] + w, f[to] = f[p], q.push(MP(-d[to], to));
            else if(d[to] == d[p] + w) f[to] = (f[to] + f[p]) % mod1;
        }
    }
}
signed main() {
    scanf("%d %d %d %d", &N, &M, &S, &T);

    for(int i = 1; i <= M; i++) {
        int x, y, z;
        cin >> x >> y >> z; 
        E[i] = (Edge) {x, y, z};
        v[x].push_back(MP(y, z)); 
        t[y].push_back(MP(x, z));
    }
    Dij(S, dis, f, 1); 
    Dij(T, rdis, g, 2);
    for(int i = 1; i <= M; i++) {
        int x = E[i].u, y = E[i].v;LL w = E[i].w;
        if((dis[x] + w + rdis[y] == dis[T]) && (1ll * f[x] * g[y] % mod1 == f[T])) printf("YES\n");
        else {
            LL ned = dis[T] - dis[x] - rdis[y] ;
            if(ned <= 1) printf("NO\n");
            else printf("CAN %lld\n", w - ned + 1);
        }
    }
    return 0;
}