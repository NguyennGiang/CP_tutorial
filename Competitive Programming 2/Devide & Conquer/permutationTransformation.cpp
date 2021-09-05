#include <bits/stdc++.h>
using namespace std;

void build(int l, int r, vector <int> const &a, vector <int> &d, int curD = 0){
    if (r < l){
        return ;
    }

    if (l == r){
        d[l] = curD;
        return;
    }

    int m = l;
    for (int i = l + 1; i <= r; i++){
        if (a[m] < a[i]){
            m = i;
        }
    }

    d[m] = curD;
    build(l, m - 1, a, d, curD + 1);
    build(m + 1, r, a, d, curD + 1);
}

void solve(){
    int n;
    cin >> n;
    vector <int> a(n);
    for (int &x : a) cin >> x;

    vector <int> d(n);
    build(0, n - 1, a, d);
    for (int x : d) {
        cout << x << " ";
    }
    cout << '\n';
}

int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}