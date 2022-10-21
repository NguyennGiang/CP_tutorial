/*
    problem discription: https://oj.vnoi.info/problem/colquery
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

int n, q;
int a[N];

struct DSU {
    vector<map<int,int>> color;
    vector<int> parent, size;

    DSU(int n) : color(n), parent(n), size(n) {}

    void make_set(int u){
        color[u][a[u]] = 1;
        parent[u] = u;
        size[u] = 1;
    }

    int find_set(int u){
        if (u == parent[u]) return u;
        int p = find_set(parent[u]);
        parent[u] = p;
        return p;
    }

    void join_set(int a, int b){
        a = find_set(a);
        b = find_set(b);

        if (a != b){
            if (size[a] < size[b]) swap(a, b);

            parent[b] = a;
            size[a] += size[b];
            for (auto p : color[b]) color[a][p.first] += p.second;
            color[b].clear();
        }
    }

    int query(int u, int c){
        u = find_set(u);
        return color[u].find(c) != color[u].end() ? color[u][c] : 0;
    }
};

void solve(){
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];

    DSU g(n + 5);
    for (int i = 1; i <= n; i++) g.make_set(i);   

    while(q--){
        int op, u, v;
        cin >> op >> u >> v;
        if (op == 1){
            g.join_set(u, v);
        }
        else cout << g.query(u, v) << endl;        
    } 
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifdef ONLINEJUDGE
        clock_t tStart = clock();
        freopen("input.txt","r",stdin); 
        freopen("output.txt","w",stdout); 
    #endif

    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }

    #ifdef ONLINEJUDGE
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC); 
    #endif
    return 0;
}