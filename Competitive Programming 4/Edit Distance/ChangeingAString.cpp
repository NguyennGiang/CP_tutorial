#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MOD = 1e9 + 7;

const int N = 1e3 + 10;
int f[N][N];
int editDistance(const string &s, const string &t, int n, int m){
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
                f[i][j] = min({f[i-1][j-1], f[i-1][j], f[i][j-1]}) + 1;
            }
        }
    }
    return f[n][m];
}

void trace(const string &s, const string &t, int n, int m)
{
    while (n > 0 && m > 0){
        if (s[n- 1] == t[m - 1]){
            n--, m--;
        }
        else if (f[n-1][m-1] == f[n][m] - 1){
            cout << "REPLACE " << n << " " << t[m-1] << '\n';
            n--;
            m--;
        }
        else if (f[n-1][m] == f[n][m] - 1){
            cout << "DELETE " << n << endl;
            n--;
        }
        else {
            cout << "INSERT " << n + 1 << ' ' << t[m-1] << endl;
            m--;
        }
    }
    while(m > 0) cout << "INSERT 1 " << t[--m] << endl;
    while(n > 0) cout << "DELETE " << n-- << endl;
}
void solve(){
    string s, t;
    cin >> s >> t;
    int n = s.length(), m = t.length();
    cout << editDistance(s, t, n, m) << endl;
    trace(s, t, n, m);
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