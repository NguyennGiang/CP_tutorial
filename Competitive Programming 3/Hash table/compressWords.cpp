#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MOD = 1e9 + 7;
const int N = 1e5 + 5;
ll hash1[N], hash2[N];
string s, ans;
ll p1[N];
int main(){
    // Base 131
    p1[0] = 1;
    for (int  i = 1; i < N; i++) p1[i] = (p1[i-1] * 131) % MOD;
    int n;
    cin >> n;
    cin >> ans;
    for (int i = 1; i <= ans.length(); i++){
        hash1[i] = (hash1[i-1] * 131 + ans[i-1]) % MOD;
    }
    for (int i = 2; i <= n; i++){
        cin >> s;
        int len1 = ans.length();
        int len2 = s.length();
        int pos = 0;
        hash2[0] = 0;
        for (int j = 1; j <= min(len1, len2); j++){
            hash2[j] = (hash2[j-1] * 131 + s[j-1]) % MOD;
            ll t1 = (hash1[len1] - (hash1[len1 - j] * p1[j]) % MOD + MOD) % MOD;
            if (t1 == hash2[j]) pos = j;
        }

        if (pos < len2) ans += s.substr(pos);
        for (int j = len1 + 1; j <= ans.length(); j++){
            hash1[j] = (hash1[j-1] * 131 + ans[j-1]) % MOD;
        }
    }
    cout << ans << endl;
    return 0;
}

// Time: O(len1 + len2 + len3 + ...)