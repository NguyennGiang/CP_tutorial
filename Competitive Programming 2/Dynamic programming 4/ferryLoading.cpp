#include <bits/stdc++.h>
using namespace std;

vector <int> car;
int dp[10001][201];
bool flag[10001][201];

int go(int i, int l, int r){
    if (i == car.size() || l - car[i] < 0 && r - car[i] < 0){
        return 0;
    }
    if (dp[l][i] != -1) return dp[l][i];
    int x = 0, y = 0;
    if (l - car[i] >= 0) x = go(i + 1, l - car[i], r);
    if (r - car[i] >= 0) y = go(i + 1, l, r - car[i]);
    if (x >= y && l - car[i] >= 0) flag[l - car[i]][i] = true;
    return dp[l][i] = 1 + max(x, y);
}

int main(){
    int t;
    cin >> t;
    while (t--){
        int ferry;
        cin >> ferry;
        int tmp;
        while (cin >> tmp && tmp){
            car.push_back(tmp);
        }
        memset(dp, -1, sizeof(dp));
        memset(flag, false, sizeof(flag));
        ferry *= 100;
        int load = go(0, ferry, ferry);
        cout << load << endl;
        int i = 0;
        while (ferry >= 0 && i < load){
            if (ferry - car[i] >= 0 && flag[ferry-car[i]][i]){
                cout << "port\n";
                ferry -= car[i];
            }
            else cout << "starboard\n";
            i++;
        }
        car.clear();
        cout << endl;
    }
    return 0;
}