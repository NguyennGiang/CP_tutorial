#include<bits/stdc++.h>
using namespace std;
#define KAMEHAMEHA ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fi first
#define se second
#define ll long long
typedef pair<int, int> pii;
ll gcd(ll a, ll b) {return b == 0? a : gcd(b, a % b);}
ll lcm(ll a, ll b) {return a * b / gcd(a, b);}

int n, m;
ll a[20];

void solve(){
    int num;
    int ans = n;
    ll sum;

    for (int i = 1; i < (1 << m); i++){
        num = 0;
        sum = 1ll;
        for (int j = 0; j < m; j++){
            if (i & (1 << j)){
                num++;
                sum = lcm(sum, a[j]);
            }
        }
        if (num & 1) ans -= n / sum;
        else ans += n / sum;
    }
    cout << ans << endl;
}

int main(){

    KAMEHAMEHA
    while(cin >> n >> m){
        for (int i = 0; i < m; i++){
            cin >> a[i];
        }
        solve();
    }
    return 0;
}