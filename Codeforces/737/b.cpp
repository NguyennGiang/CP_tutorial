#include <bits/stdc++.h>
using namespace std;
int main ()
{
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector <pair<int, int>> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i].first;
            a[i].second = i;
        }
        sort(a.begin(), a.end());
        int ans = 1;
        for (int i = 1; i < n; i++){
            if (a[i].second != a[i-1].second + 1){
                ans++;
            }
        }
        if (ans <= k){
            cout << "Yes\n";
        }
        else {
            cout << "No\n";
        }
    }
    return 0;
}