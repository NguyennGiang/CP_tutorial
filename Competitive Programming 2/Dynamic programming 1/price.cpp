#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAX = 305;

int main(){
    vector <vector <ll>> dp(MAX, vector <ll>(MAX, 0));

    //base case
    for (int i = 0; i < MAX; i++){
        dp[0][i] = 1;
    }

    for (int i = 1; i < MAX; i++){
        for (int j = 1; j < MAX; j++){
            dp[i][j] = dp[i][j - 1] + (i >= j? dp[i-j][j] : 0);
        }
    }
    string s;
    while (getline(cin, s)){
        vector <int> v;
        int res = 0;
        for (int i = 0; i < s.length(); i++){
            if (s[i] <= '9' && s[i] >= '0'){
                res = res * 10 + (s[i] - '0');
            }
            else {
                v.push_back(res);
                res = 0;
            }
        }
        v.push_back(res);
        int l, r;
        int n = v[0];
        if (v.size() == 1){
            l = 0;
            r = v[0];
        }
        else if (v.size() == 2){
            l = 0;
            r = v[1];
        }
        else {
            l = v[1];
            r = v[2];
        }
        if (n == 0){
            if (l > 0){
                cout << 0 << endl;
            }
            else {
                cout << 1 << endl;
            }
        }
        else {
            cout << dp[n][min(300, r)] - dp[n][min(300, max(0, l - 1))] << endl;
        }
    }
    return 0;
}