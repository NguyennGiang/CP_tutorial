#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int y, z; cin >> y >> z;
    for (int i = 0; i < n; i++){
        a[i] = abs(a[i] - z);
    }
    sort(a.begin(), a.end());
    int res = 0, tot = 0;
    y = abs(y - z);
    for (int v : a){
        tot += v;
        if (tot < y) res++;
        else break;
    }
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}
