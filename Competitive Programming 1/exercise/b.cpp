#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int maxn = 1e9;

int main() {
    int t;
    cin >> t; 
    for (int i = 1; i <= t; i++){
        ll n, k;
        cin >> n >> k;
        cout << "Case #" << i << ": ";
        ll s = 1 << n;
        if( (k % s) == (s -1)) {
            cout << "ON\n";
        } else {
            cout << "OFF\n";
        }
    }
    return 0;
}