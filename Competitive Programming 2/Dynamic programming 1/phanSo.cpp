#include <bits/stdc++.h>
using namespace std;

long long dp[205];

long long solve(vector <int> &fac, int target){
    if (target == 0) return 1;
    if (target < 0) return 0;
    if (dp[target] != -1) return dp[target];

    long long res = 0;
    for (int i = 0; i < fac.size(); i++){
        res += solve(fac, target - fac[i]);
    }
    return dp[target] = res;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector <int> fac;
    for (int i = 2; i <= k; i++){
        if (k % i == 0){
            fac.push_back(i);
        }
    }
    memset(dp, -1, sizeof(dp));
    dp[0] = 1;
    int x = solve(fac, n);  
    if (x == 0) cout << 0;
    else {
        int m = fac.size();
        vector <int> res;
        while (n > 0){
            int cnt = 0;
            while (n >= fac[m - 1] && dp[n - fac[m - 1]] > 0){
                cnt++;
                n -= fac[m - 1];
            }
            if (cnt > 0) cout << fac[m - 1] << " "  << cnt << endl;
            m--;
        }
    }
    return 0;
}