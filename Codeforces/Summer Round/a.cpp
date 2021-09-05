#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int a, b;
        cin >> a >> b;
        int ans;
        if ((a + b) % 2 == 1){
            ans = -1;
        }
        else if (a == b){
            ans = 1;
        }
        else ans = 2;

        if (a == 0 && b == 0){
            ans = 0;
        }
        cout << ans << '\n';
    }
    return 0;
}