/*
    problem discription: https://codeforces.com/contest/722/problem/C
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MOD = 1e9 + 7;

const int N = 100000 + 5;
int a[N], p[N], flag[N];
int n;
long long ans, res[N];

struct DSU
{
    vector<int> parent, size;
    vector<long long> sum;

    DSU(int n) : parent(n), size(n), sum(n) {}

    void make_set(int u){
        parent[u] = u;
        size[u] = 1;
        sum[u] = a[u];
    }

    int find_set(int u){
        return u == parent[u] ? u : parent[u] = find_set(parent[u]);
    }

    void join_set(int u, int v){
        u = find_set(u);
        v = find_set(v);

        if (u != v){
            if (size[u] < size[v]){
                swap(u, v);
            }
            parent[v] = u;
            size[u] += size[v];
            sum[u] += sum[v];
        }
    }
};

void solve(){
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> p[i];

    DSU g(n + 5);
    for (int i = 1; i <= n; i++) g.make_set(i);
    for (int i = n; i >= 1; i--){
        flag[p[i]] = true;
        if (p[i] > 1 && flag[p[i] - 1]) g.join_set(p[i], p[i] - 1);
        if (p[i] < n && flag[p[i] + 1]) g.join_set(p[i], p[i] + 1);

        ans = max(ans, g.sum[g.find_set(p[i])]);
        res[i-1] = ans;
    }

    for (int i = 1; i <= n; i++) cout << res[i] << endl;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // #ifdef ONLINEJUDGE  
    //     clock_t tStart = clock();
    //     freopen("input.txt","r",stdin); 
    //     freopen("output.txt","w",stdout); 
    // #endif

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