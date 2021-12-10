#include<bits/stdc++.h>
using namespace std;
#define KAMEHAMEHA ios_base::sync_with_stdio(0); cin.tie(0);
const int N = 1000010, mod = 1e9 + 7;
long long ans;

int n, m;
string s;
int z[N], p[N];

void z_function(string s){
    int n = s.length();
    for (int i = 1, l = 0, r = 0; i < n; i++){
        if(i <= r) z[i] = min(r - i + 1, z[i-l]);
        while (i +z[i] < n && s[i + z[i]] == s[z[i]]) z[i]++;
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
}

int main(){
    KAMEHAMEHA

    cin >> n >> m >> s;

    z_function(s);

    p[0] = 1;
    for (int i = 1; i < N; i++) p[i] = 1ll * p[i-1] * 26 % mod;

    if (m == 0){
        cout << p[n] << endl;
        return 0;
    }

    int r;
    int len = s.size();
    for (int i = 1; i <= m; i++){
        int x;
        cin >> x;
        if (i == 1){
            ans = p[x-1];
            r = x + len - 1;
            continue;
        }
        if(x > r) ans = 1ll * ans * p[x - r - 1] % mod;
        else {
            if (z[x-r+len-1] < r - x + 1){
                cout << 0 << endl;
                return 0;
            }
        }
        r = x + len - 1;
        if (r > n){
            cout << 0 << endl;
            return 0;
        }
    }
    if (r < n) ans = 1ll * ans * p[n-r] % mod;
    cout << ans << endl;
    return 0;
}
