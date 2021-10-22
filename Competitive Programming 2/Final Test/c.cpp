#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while (cin >> n && n != 0){
        vector <int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        int tmp = 0;
        int ans = INT_MIN;
        for (int x : a){
            tmp += x;
            ans = max(ans, tmp);
            tmp = max(tmp, 0);
        }
        if (ans > 0){
            cout << "The maximum winning streak is " << ans << ".\n";
        }
        else {
            cout << "Losing streak.\n";
        }
    }
    return 0;
}