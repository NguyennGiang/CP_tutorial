#include <bits/stdc++.h>
using namespace std;

int n, m;
char pass[11][36];
int num[11];
int ans;
void solve(int t){
    for (int i = 0; i < m; i++){
        if (num[i] < 0){
            return;
        }
    }

    if (t == n){
        for (int i = 0; i < m; i++){
            if (num[i] > 0){
                return;
            }
        }
        ans++;
        return;
    }

    for (int i = 0; i <= 1; i++){
        for (int j = 0; j < m; j++){
            if (pass[j][t] == (i + '0')) num[j]--; 
        }

        solve(t+1);

        for (int j = 0; j < m; j++){
            if (pass[j][t] == (i + '0')) num[j]++;
        }
    }
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        cin >> pass[i] >> num[i];
    }
    solve(0);
    cout << ans;
    return 0;
}