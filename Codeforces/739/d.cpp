#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t;
    cin >> t;
    while (t--){
        string n;
        cin >> n;
        int ans = 100;
        for (int i = 0; i < 60; i++){
            ll x = (1LL << i);

            string s = to_string(x);
            int saved = 0, k = 0;

            while(saved < s.length() && k < n.length()){
                if (n[k] == s[saved]){
                    saved++;
                }
                k++;
            }
            ans = min(ans, (int)n.length() + (int)s.length() - 2 * saved);
        }
        cout << ans << '\n';
    }
    return 0;
}