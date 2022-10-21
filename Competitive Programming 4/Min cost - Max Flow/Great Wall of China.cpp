/*  
    From: Uva
*/

#include<bits/stdc++.h>
using namespace std;

const int N = 1010;
const int INF = 1 << 30;
bool inque[N];
int d[N];
int p[N];
int a[N];
int pre[N];
char str[5][N];
int n, m, s, t;

struct Edge {
    int u, v, cap, cost, next;
    Edge(){}
    Edge(int u, int v, int cap, int cost, int next): u(u), v(v), cap(cap), cost(cost), next(next) {}

}e[1000 * N];

int ecnt;

int getId(int x, int y){
    // cout << x << ' ' << y << ' ' << x * n + y + 1 << endl;
    return x * n + y + 1;
}

void addEdge(int u, int v, int cap, int cost){
    e[ecnt] = Edge(u, v, cap, cost, pre[u]);
    pre[u] = ecnt++;
    e[ecnt] = Edge(v, u, 0, -cost, pre[v]);
    pre[v] = ecnt++;
}

bool spfa(int &flow, int &cost){
    for (int i = s; i <= t; i++) d[i] = INF;
    memset(inque, 0, sizeof(inque));
    d[s] = 0, p[s] = 0, a[s] = INF;
    queue<int> q;
    q.push(s);

    while(!q.empty()){
        int u = q.front();
        q.pop();
        inque[u] = false;

        for (int i = pre[u]; ~i; i = e[i].next){
            int v = e[i].v;
            if (e[i].cap > 0 && d[v] > d[u] + e[i].cost){
                d[v] = d[u] + e[i].cost;
                p[v] = i;
                a[v] = min(a[u], e[i].cap);
                if (!inque[v]){
                    q.push(v);
                    inque[v] = true;
                }
            }
        }
    }
    if (d[t] == INF) return false;
    flow += a[t];
    cost += d[t] * a[t];
    int u = t;
    while(u != s){
        e[p[u]].cap -= a[t];
        e[p[u] ^ 1].cap += a[t];
        u = e[p[u]].u;
    }
    return true;
}

int mincost(){
    int flow = 0, cost = 0;
    while(spfa(flow, cost));
    return cost;
}

void solve(){
    for (int i = 0; i < 5; i++) cin >> str[i];
    ecnt = 0;
    int B = getId(4, n - 1) + 1;
    s = 0, t = getId(5, 0) + B;
    // cout << s << ' ' << t << ' ' << B << endl;
    memset(pre, -1, sizeof(pre));
    for (int i = 0; i < 5; i++){
        if (str[i][0] == '@') addEdge(s, getId(i, 0), 1, 0);
        for (int j = 0; j < n; j++){
            if (str[i][j] == '@') addEdge(getId(i, j), getId(i, j) + B, 1, 0);
            else addEdge(getId(i, j), getId(i, j) + B, 1, str[i][j] - '0');

            if (i > 0) addEdge(getId(i, j) + B, getId(i-1, j), 1, 0);
            if (i < 4) addEdge(getId(i, j) + B, getId(i + 1, j), 1, 0);
            if (j < n - 1) addEdge(getId(i, j) + B, getId(i, j + 1), 1, 0);
            if (j > 0) addEdge(getId(i, j) + B, getId(i, j - 1), 1, 0);
        }
        addEdge(getId(i, n - 1) + B, t, INF, 0);
    }
    cout << mincost() << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(cin >> n && n){
        solve();
    }
}
