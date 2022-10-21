#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, m; cin >> n >> m;
    if (m & 1){
        cout << "1.000000\n";
    }
    else cout << "0.000000\n";
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}