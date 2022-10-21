#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MOD = 1e9 + 7;

ll gcd(ll a, ll b){
    if (!b) return a;
    return gcd(b, a % b); 
}

void solve(){
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    ll dx = abs(a-c);
    ll dy = abs(b - d);
    cout << 1LL + gcd(dx, dy) << '\n';
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifdef ONLINEJUDGE
        clock_t tStart = clock();
        freopen("input.txt","r",stdin); 
        freopen("output.txt","w",stdout); 
    #endif

    int t;
    cin >> t;
    int cs = 1;
    while(t--){
        cout << "Case " << cs++ << ": ";
        solve();
    }

    #ifdef ONLINEJUDGE
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC); 
    #endif
    return 0;
}