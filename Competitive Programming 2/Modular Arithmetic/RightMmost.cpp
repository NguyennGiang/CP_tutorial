#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector <long long> a(n);
        for (long long &ai : a) cin >> ai;

        int cnt = 0;
        for (int i = 0; i < n; i++){
            while (a[i] % 5 == 0 && a[i] > 0){
                a[i] /= 5;
                cnt++;
            }
        }

        for (int i = 0; i < n; i++){
            while(a[i] > 0 && cnt > 0 && a[i] % 2 == 0){
                a[i] >>= 1;
                cnt--;
            }
        }

        long long ans = 1;
        for (long long ai : a){
            ans = (ans * ai) % 10;
        }
        if (cnt){
            ans = (ans * 5) % 10;
        }
        if (ans){
            cout << ans;
        }
        else {
            cout << -1;
        }
        cout << '\n';
    }
    return 0;
}