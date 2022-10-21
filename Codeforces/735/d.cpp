#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        string res = "";
        if (n == 1){
            cout << "a" << endl;
            continue;
        }
        // n == 6 --> a [0: 2]
        for (int i = 0; i < n / 2; i++){
            res += "a";
        }
        if (n & 1) res += "bc";
        else res += "b";
        for (int i = 0; i + 1 < n / 2; i++){
            res += "a";
        }
        cout << res << endl;
    }
    return 0;
}