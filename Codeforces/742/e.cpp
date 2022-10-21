#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, q;
    cin >> n >> q;
    vector <int> a(n);
    for (int &ai : a) cin >> ai;

    while(q--){
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1){
            a[l-1] = r;
        }
        else {
            l--, r--;
            int res = 0;
            int x = l;
            for (int i = l; i <= r; i++){
                if (a[i] > a[i + 1] || i == r){
                    res += (i - x + 1) * (i - x) / 2;
                    res += (i - x + 1);
                    x = i + 1;
                }
            }
            cout << res << endl;
        }
    }
    return 0;
}