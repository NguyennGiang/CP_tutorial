#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    const int M = 1e9 + 7;
    for (int tc = 1; tc <= t; tc++){
        int n;
        string s;
        cin >> n >> s;
        int pre = -1;
        long long total = 0;
        for (int i = 0; i < n; i++){
            if (s[i] == 'X' || s[i] == 'O'){
                if (pre >= 0 && s[i] != s[pre]){
                    total += 1LL * (pre + 1) * (n - i);
                    total %= M;
                }
                pre = i;
            }
        }
        cout << "Case #" << tc << ": " << total << '\n'; 
    }
    return 0;
}