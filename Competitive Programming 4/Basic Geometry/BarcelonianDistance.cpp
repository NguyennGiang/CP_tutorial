#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MOD = 1e9 + 7;
typedef long double lb;
ll a, b, c, m, n, p, q;
long double x[10], y[10], res;

long double dis(lb m, lb p, lb n, lb q){
    return sqrt((m - n) * (m - n) + (p - q) * (p - q));
}

void solve(){
    cin >> a >> b >> c;
    cin >> m >> p >> n >> q;
    res = abs(m-n) + abs(p-q);
    c = -c;
    if (m == n || p == q || a == 0 || b == 0){
        cout << res;
        return;
    }
    if (m > n) {
        swap(m, n);
        swap(p, q);
    }

    x[1] = (1.0 * c - b * p) / a, y[1] = p;
    x[2] = (1.0 * c - b * q) / a, y[2] = q;

    y[3] = (1.0 * c - a * m) / b, x[3] = m;    
    y[4] = (1.0 * c - a * n) / b , x[4] = n;
    // for (int i = 1; i <= 4; i++) cout << x[i] << ' ' << y[i] << endl;
    for(int i = 1; i <= 4; i++){
        for (int j = 1; j <= 4; j++){
            lb s1 = fabs(m - x[i]) + fabs(p - y[i]);
            lb s2 = dis(x[i], y[i], x[j], y[j]);
            lb s3 = fabs(n - x[j]) + fabs(q - y[j]);
            res = min(res, s1 + s2 + s3);
        }
    }

    cout << fixed << setprecision(7) << res << endl;
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
    //  cin >> t;
    while(t--){
        solve();
    }

    #ifdef ONLINEJUDGE
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC); 
    #endif
    return 0;
}