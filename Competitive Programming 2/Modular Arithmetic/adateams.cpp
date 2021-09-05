#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int mod = 1e9 + 7;
const int N = 1e6 + 5;
int n, a, b, d;
int fac[N], inv[N];

int bin_pow(int a,int b){
    if (b == 0){
        return 1;
    }

    if (b & 1){
        return 1LL * a * bin_pow(a, b - 1) % mod;
    }

    int x = bin_pow(a, b >> 1);
    return (1LL * x * x) % mod;
}

int formula(int n, int k){
    return 1LL * fac[n] * inv[k] % mod * inv[n - k] % mod;  
}

void init(){
    fac[0] = 1;
    inv[0] = 1;
    for (int i = 1; i < N; i++){
        fac[i] = (1LL * fac[i - 1] * i) % mod;
        inv[i] = bin_pow(fac[i], mod - 2);
    }
}

int main(){
    init();
    int n, a, b, d;
    while(cin >> n >> a >> b >> d){
        int ans = 1LL * formula(n, a) * bin_pow(formula(b, d), a) % mod;
        cout << ans << endl;
    }
    return 0;
}
