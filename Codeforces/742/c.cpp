#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string n;
        cin >> n;
        int even = 0, odd = 0;
        for (int i = 0; i < n.length(); i++){
            if (i & 1){
                odd = odd * 10 + (n[i] - '0');
            }
            else even = even * 10 + (n[i] - '0');
        }
        cout << (odd + 1) * (even + 1) - 2 << endl;
    }
    return 0;
}