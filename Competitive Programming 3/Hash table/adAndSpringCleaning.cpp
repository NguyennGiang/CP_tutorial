#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
typedef pair <ll, ll> pll;

const ll MOD1 = 1e9 + 7, MOD2 = 995329;
const ll B1 = 131, B2 = 151;
const int N = 1e5 + 5;
pll h[N], p[N];
int n, k;
string s;

pll get(int l, int r){
    return {(h[r].f - (h[l-1].f * p[r - l + 1].f) % MOD1 + MOD1) % MOD1, (h[r].s - (h[l-1].s * p[r - l + 1].s) % MOD2 + MOD2) % MOD2};
}

int main(){
    int t;
    cin >> t;
    while (t--){
        cin >> n >> k >> s;

        h[0] = {0, 0}, p[0] = {1, 1};
        for (int i = 1; i <= n; i++){
            h[i].f = (h[i-1].f *  B1 + s[i - 1] - 'a' + 1) % MOD1;
            p[i].f = (p[i-1].f * B1) % MOD1;
            h[i].s = (h[i-1].s *  B2 + s[i - 1] - 'a' + 1) % MOD2;
            p[i].s = (p[i-1].s * B2) % MOD2;

        } 
        //for (int i = 0; i <= n; i++) cout << h[i] << " ";
        set <pll> res;
        for (int i = k; i <= n; i++){
            pll tmp = get(i - k + 1, i);
            res.insert(tmp);
        }
        cout << res.size() << endl;
    }
    return 0;
}

// Time O(n * t);