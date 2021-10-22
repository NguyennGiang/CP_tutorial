#include <bits/stdc++.h>
using namespace std;

int n, k;
vector <int> dp;
vector <vector <int>> ar;
vector <vector <int>> pos;

int func(int pre){
    if (dp[pre] != -1) return dp[pre];

    int res = 0;
    for (int i = 1; i <= n; i++){
        bool f = true;
        for (int j = 0; j < k; j++){
            if (pos[j][i] <= pos[j][pre]){
                // cannot choose i for LCS, because it comes before pre;
                f = false;
                break;
            }
        }
        if (f) res = max(res, func(i) + 1);
    }
    return dp[pre] = res;
}

int main(){
    cin >> n >> k;
    dp.assign(n + 1, -1);
    ar = vector <vector <int>> (k , vector <int>(n + 1));
    pos = vector <vector <int>> (k, vector <int> (n + 1));

    for (int i = 0; i < k; i++){
        for (int j = 1; j <= n; j++){
            cin >> ar[i][j];
            pos[i][ar[i][j]] = j;
        }
    }
    cout << func(0) << endl;
}