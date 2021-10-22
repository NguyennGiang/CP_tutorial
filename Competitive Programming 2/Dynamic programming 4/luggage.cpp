#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    getchar();
    string s;
    while (t--){
        int sum = 0;
        getline(cin, s);
        vector <int> weight(25);
        int n = 0;
        stringstream ss(s);
        while (ss >> weight[n]){
            sum += weight[n];
            n++;
        }
        bool dp[sum + 1];
        if (sum % 2) {
            cout << "NO\n";
            continue;
        }
        memset(dp, false, sizeof(dp));
        dp[0] = true;
        for (int i = 0; i < n; i++){
            for (int j = sum; j >= weight[i]; j--){
                if (dp[j - weight[i]]){
                    dp[j] = true;
                }
            }
        }
        if (dp[sum/2]) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}