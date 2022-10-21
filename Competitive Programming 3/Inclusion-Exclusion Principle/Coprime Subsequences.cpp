#include<bits/stdc++.h>
using namespace std;
#define KAMEHAMEHA ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fi first
#define se second
#define ll long long
#define mod 1000000007
#define N 100007
typedef pair<int, int> pii;
ll gcd(ll a, ll b) {return b == 0? a : gcd(b, a % b);}
ll lcm(ll a, ll b) {return a * b / gcd(a, b);}

ll qp(ll m, ll n){
    if (n == 0) return 1LL;
    ll x = qp(m, n / 2);
    x = x * x % mod;
    if (n & 1) {
        x = x * m % mod;
    }
    return x;
}

ll h[N], f[N];

void solve(){
    int n, m;
    cin >> n;
    while(n --){
        cin >> m;
        for (int i = 1; i * i <= m; i++){
            if (m % i == 0){
                h[i]++;
                if (i * i != m){
                    h[m/i]++;
                }
            }
        }
    }
    for (int i = 1; i <= 100000; i++){
        f[i] = qp(2, h[i]) - 1;
    }

    for (int i = 100000; i; i--){
        for (int j = i + i; j <= 100000; j += i){
            f[i] = (f[i] - f[j] + mod) % mod;
        }
    }
    cout << f[1] << endl;
}

int main(){

    KAMEHAMEHA
    solve();
    return 0;
}