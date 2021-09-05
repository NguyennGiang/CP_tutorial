#include <bits/stdc++.h>
using namespace std;
int n, h, ans;
string s; 

int main() {
    cin >> n; 
    cin >> s; 
    for (int i = 0; i < n; i ++) {
          if (s[i] == 'H') h++;
    } 
    ans = 1e9;
    s = s + s; 
    for (int i = 0; i < n; i++) {
        int t = 0; 
        for (int j = i; j < i + h; j++) {
            if (s[j] == 'T') {
                t++;
            }
        }
        ans = min(ans, t);
    }
    cout << ans << '\n';

    return 0;

}