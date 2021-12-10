#include<bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin >> s;
    int n = s.length();
    vector <int> z(n, 0);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++){
        if (i <= r){
            z[i] = min(z[i-l], r - i + 1);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]){
            z[i]++;
        }
        if (i + z[i] - 1 < n){
            l = i;
            r = i + z[i] - 1;
        }
        if (z[i] == n - i && n % i == 0 ){
            cout << i << endl;
            return;
        }
    }
    cout << n << endl;
    return;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
