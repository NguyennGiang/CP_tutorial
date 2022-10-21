#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MOD = 1e9 + 7;

const int N = 1e5 + 5;

struct node {
    ll x1, x2;
}a[N];

bool cmp(node a, node b){
    if (a.x1 < b.x1) return 1;
    else if (a.x1 == b.x1) return a.x2 < b.x2;
    return 0;
}

void solve(){
    int n;
    cin >> n;

    ll l, r; cin >> l >> r;
    for (int i = 0; i < n; i++){
        ll k, b; cin >> k >> b;
        a[i].x1 = k * l + b;
        a[i].x2 = k * r + b;
    }

    sort(a, a + n, cmp);

    for (int i = 1; i < n; i++){
        if (a[i].x2 < a[i-1].x2) {
            cout << "YES";
            return;
        }
    }
    cout << "NO";
    return;
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