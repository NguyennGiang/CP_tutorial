#include <bits/stdc++.h> 
#define ll long long 

using namespace std; 

int main() {
    string s; 
    cin >> s;
    int n = s.length();
    // cout << n << endl;
    
    ll cnt = 0; 
    if (n < 2) {
        cout << 0 << endl;
    
    }
    else{
        for (int i = 0; i < n - 2; i++){
            int flag = 0; 
            for (int j = i + 2; j < n; j++){
                for (int x = i; x < j - 1; x++){
                    for (int k = 1; (x + 2 * k) <= j; k++) {
                        if (s[x] == s[x + k] && s[x] == s[x+2*k]) {
                            flag = 1;
                            cnt = cnt + n - j;  
                            break;
                        }
                    }
                    if (flag == 1) {
                        break;
                    }
                }
                if (flag == 1) {
                    break;
                }
            }
        }
    }
    cout << cnt << endl;
    return 0;
}