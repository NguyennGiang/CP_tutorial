/*
    problem description: https://oj.vnoi.info/problem/segtree_itez2
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MOD = 1e9 + 7;

const int N = 1e5 + 5;
long long st[4 * N];
int n, q;

void update(int id, int l, int r, int i, int val){
    if (l > i || r < i){
        return ;
    }
    if (l == r){
        st[id] = val;
        return ;
    }

    int mid = (l + r) >> 1;
    update(id * 2, l, mid, i, val);
    update(id * 2 + 1, mid + 1, r, i, val); 

    st[id] = st[id * 2] + st[id * 2 + 1];
}

long long get(int id, int l, int r, int u, int v){
    if (l > v || r < u) return 0;
    if (l >= u && r <= v) return st[id];

    int mid = l + r >> 1;
    long long get1 = get(id * 2, l, mid, u, v);
    long long get2 = get(id * 2 + 1, mid + 1, r, u, v);
    return get1 + get2;
}

void solve(){
    cin >> n >> q;

    while(q--){
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1){
            update(1, 1, n, x, y);
        }
        else {
            cout << get(1, 1, n, x, y) << endl;
        }
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