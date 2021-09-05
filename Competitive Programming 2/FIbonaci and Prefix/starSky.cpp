#include <bits/stdc++.h>
using namespace std;

int mp[105][105][15];

int main(){
    int n, q, c;
    cin >> n >> q >> c;
    for (int x, y, s, i = 0; i < n; i++){
        cin >> x >> y >> s;
        mp[x][y][s]++;
    }

    for (int i = 1; i <= 100; i ++){
        for (int j = 1; j <= 100; j++){
            for (int k = 0; k <= c; k++){
                mp[i][j][k] = mp[i-1][j][k] + mp[i][j-1][k] - mp[i-1][j-1][k] + mp[i][j][k];
            }
        }
    }
    while (q--){
        int t, x1, y1, x2, y2;
        cin >> t >> x1 >> y1 >> x2 >> y2;
        int ans = 0;
        for (int k = 0; k <= c; k++){
            int tmp = (k + t) % (c + 1);
            int cnt = mp[x2][y2][k] - mp[x1-1][y2][k] - mp[x2][y1-1][k] + mp[x1-1][y1-1][k]; 
            ans += tmp * cnt; 
        }
        cout << ans << '\n';
    }
    return 0;
}