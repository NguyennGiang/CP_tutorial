#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10, base = 131, MOD = 1e9 + 7;
long long h1[N], h2[N], p[N];
char str[N];

long long get1(int l, int r){
    return (h1[r] - (h1[l-1] * p[r-l+1]) % MOD + MOD) % MOD;
}

long long get2(int l, int r){
    return (h2[l] - (h2[r + 1] * p[r-l+1]) % MOD + MOD) % MOD;
}

int main(){
    int t;
    cin >> t;
    while (t--){
        scanf("%s", str + 1);
        int n = strlen(str + 1);
        cout << n << endl;
        p[0] = 1, h2[n+1] = 0;
        for (int i = 1; i <= n; i++){
            h1[i] = (h1[i-1] * base + str[i] - 'a' + 1) % MOD;
            h2[n-i+1] = (h2[n-i+2] * base + str[n-i+1] - 'a' + 1) % MOD;
            p[i] = (p[i-1] * base) % MOD;
        }
        int l = 0, r = n + 1;
        while(str[l+1] == str[r-1] && l + 1 < r - 1) l++, r--;
        int nl = l, nr = r;
        for (int i = r - 1; i >= l + 1; i--) {
            if (get1(l + 1, i) == get2(l + 1, i)){
                nl = i;
                break;
            }
        }

        for (int i = l + 1; i <= r - 1; i++){
            if (get1(i, r - 1) == get2(i, r - 1)){
                nr = i;
                break;
            }
        }

        if (nl - l > r - nr){
            for (int i = 1; i <= nl; i++) cout << str[i];
            for (int i = r; i <= n; i++) cout << str[i];
        }
        else {
            for (int i = 1; i <= l; i++) cout << str[i];
            for (int i = nr; i <= n; i++) cout << str[i];
        }
        cout << endl;
    }
    return 0;
}

// Time O(T * N);