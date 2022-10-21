#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MOD = 1e9 + 7;

int n,m;
string s,t;

void solve(){
    while(cin >> n){
        cin >> s >> m >> t;

        int f[n+1][m+1];
        for (int i = 0; i <= m; i++){
            f[0][i] = i;
        }
        for (int i = 0; i <= n; i++){
            f[i][0] = i;
        }

        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                if (s[i - 1] == t[j - 1]){
                    f[i][j] = f[i-1][j-1];
                }
                else {
                    f[i][j] = min({f[i-1][j-1], f[i][j-1], f[i-1][j]}) + 1;
                }
            }
        }
        cout << f[n][m] << endl;
    }
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