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

ll s[5];

ll work(ll m){
    ll ans = 0;
    for (int i = 1; i < (1 << 5); i++){
        ll sum = 1, num = 0;
        for (int j = 0; j < 5; j++){
            if (i & (1 << j)){
                num++;
                sum = lcm(sum, s[j]);
            }
        }
        if (num & 1){
            ans += m / sum;
        }
        else ans -= m / sum;
    }
    return ans;
}

void solve(){
    ll m, n, a, d;
    cin >> m >> n >> a >> d;

    for (int i = 0; i < 5; i++){
        s[i] = a + i * d;
    }
    ll len = work(n) - work(m - 1);

    cout << n - m + 1 - len << endl;
}

int main(){

    KAMEHAMEHA
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
