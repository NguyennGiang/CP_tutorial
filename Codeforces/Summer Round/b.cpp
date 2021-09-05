#include <bits/stdc++.h>
using namespace std;

int n;

int check(string &s, string &t){
    vector <int> f[2];

    for (int i = 0; i < n; i++){
        if (s[i] != t[i]){
            if (s[i] & 1){
                f[1].push_back(i);
            }
            else f[0].push_back(i);
        }
    }
    for (int i = 0; i < 2; i ++){
        sort(f[i].begin(), f[i].end());
    }
    int cnt = 0;
    for (int i = 0; i < min(f[0].size(), f[1].size()); i++){
        cnt += abs(f[0][i] - f[1][i]);
    }
    return cnt;
}

void solve(){
    cin >> n;
    int f[2]= {0, 0};
    vector <int> a(n);

    for (auto &ai : a){
        cin >> ai;
        ai &= 1;
        f[ai]++;
    }
    if (n == 1){
        cout << 0;
        return ;
    }
    if (abs(f[0] - f[1]) > 1) {
        cout << -1;
        return ;
    }
    string s = "";
    for (int x : a){
        if (x) s += '1';
        else s += '0';
    }
    string t = "";
    int ans = INT_MAX;
    if (f[0] > f[1]){
        for (int i = 0; i < n; i++){
            t += ((i & 1)? '1' : '0');
        }
        ans = min(ans, check(s, t));
    }
    else if (f[1] > f[0]){
        for (int i = 0; i < n; i++){
            t += ((i & 1)? '0': '1');
        }
        ans = min(ans, check(s, t));
    }
    else {
        for (int i = 0; i < n; i++){
            t += ((i & 1)? '0' : '1');
        }
        ans = min(check(s, t), ans);
        reverse(t.begin(), t.end());
        ans = min(ans, check(s, t));
    }
    cout << ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << '\n';
    }
    return 0;
}
