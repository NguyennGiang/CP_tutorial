#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int k;
        cin >> k;
        int j = 0, res = 0, v = 1;
        while(j < k){
            if (v % 3 != 0 && v % 10 != 3){
                res = v;
                j++;
            }
            v++;
        }
        cout << res << '\n';
    }
    return 0;
}