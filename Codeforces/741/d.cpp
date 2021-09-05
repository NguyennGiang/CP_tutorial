#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int t;
    cin >> t;
    while (t--){
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        int a[n];
        for (int i = 0; i < n; i++){
            a[i] = (s[i] == '+' ? 1 : -1);
        }
        
        for (int i = 1; i < n; i += 2){
            a[i] *= -1;
        }
 
        int cs[n + 1];
        cs[0] = 0;
        for (int i = 1; i <= n; i++){
            cs[i] = cs[i-1] + a[i-1];
        }
 
        for (int qq = 0; qq < q; qq++){
            int l , r;
            cin >> l >> r;
            l--, r--;
            int ans = abs(cs[r + 1] - cs[l]);  
            if (ans == 0){
                cout << 0 << endl;
            }
            else if(ans % 2 == 0){
                cout << 2 << endl;
            }
            else {
                cout << 1 << endl;
            }
        }
    }
    return 0;
}
 
/*
    + - - + + - - - + + - + + -
    + + - - + + - + + - - - + +  
*/