#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-7;
double f[1005];
double ans[1005];
int x;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k, q; cin >> k >> q;
    f[0] = 1;
    for (int i = 1; x <= 1000; i++){
        for (int j = k; j >= 1; j--){
            f[j] = f[j] * j / k + f[j-1] * (k - j + 1) / k;
        }
        while(x <= 1000 && f[k] * 2000 >= x - eps){
                ans[x++] = i;
        }
        f[0] = 0;
    }
    
    while(q--){
        int x; cin >> x;
        cout << ans[x] << endl;
    }
    return 0;
}