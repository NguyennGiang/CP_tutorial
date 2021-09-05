#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; 
    cin >> t; 
    for (int tc = 1; tc <= t; tc++) {
        int N, S, p; 
        cin >> N >> S >> p;
        int sum[N];
        for (int i = 0; i < N; i++) cin >> sum[i];
        int cnt = 0; 
        for (int i = 0; i < N; i++) {
            if (sum[i] < p) continue;
            if (sum[i] % 3 == 0 ) {
                    int mid = sum[i] / 3;
                    if (mid >= p) {
                        cnt++;
                    }
                    else if (mid + 1 >= p && S > 0) {
                        cnt++;
                        S--;
                    }
                
            }
            else if (sum[i] % 3 == 1){
                int mid = sum[i] / 3 + 1; 
                if (mid >= p) {
                    cnt ++;
                }
            }
            else {
                int mid = sum[i] / 3 + 1;
                if (mid >= p) {
                    cnt++;
                }
                else if (mid + 1 >= p && S > 0) {
                    cnt++;
                    S--;
                }
            }
        }
        cout << "Case #" << tc << ": " << cnt << '\n';
    }
    return 0;
}