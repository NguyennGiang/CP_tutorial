/*
    problem description: https://codeforces.com/contest/616/problem/B
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MOD = 1e9 + 7;

void solve(){
    int n, m;
    cin >> n >> m;
    int ans = 0;
    int x;
    for (int i = 0; i < n; i++){
        int best = INT_MAX;
        for (int j = 0; j < m; j++){
            cin >> x;
            best = min(best, x);
        }
        ans = max(ans, best);
    }
    cout << ans;
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