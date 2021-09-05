#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc, t; 
    cin >> t; 
    for (tc = 1; tc <= t; tc++){
        int pre, result = 0, n, k; 
        cin >> n;
        k = 0;
        for (int i = 0; i < n; i++) {
            int x; 
            cin >> x; 
            while (true) {
                if (k == 0) {
                    pre = x; 
                    k = 1; 
                    break;
                }
                if (x > pre && x <= pre + 10) {
                    pre = x; 
                    k = (k + 1) % 4; 
                    break;
                }
                result++; 
                pre += 10;  
                k = (k + 1 ) % 4; 
            }
        }
        result += (4 - k) % 4;
        cout << "Case #" << tc << ": " << result << '\n';
    }
    return 0;
}