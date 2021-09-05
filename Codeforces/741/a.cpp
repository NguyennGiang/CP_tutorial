#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int l, r;
        cin >> l >> r;
        int b = r / 2 + 1;
        if (l <= b){
            cout << (r - 1) / 2 << endl;
        }
        else {
            cout << r - l << endl;
        }
    }
    return 0;
}