/*
    - Hình chữ nhật 0 1;
    - với mỗi cột thứ j, tìm f[j] là sô ô 1 liên tiếp tình từ hàng thứ i trở lên.
    - với mỗi cột j, tìm ô bên trái(l) gần nhât và bên phái(r) gần nhất có f[r], f[l] <= f[j];
    --> s = f[j] * (r - l - 1);
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int m, n;
    cin >> m >> n;

    int res = 0;
    vector <int> f(n, 0);
    vector <int> l(n), r(n);

    while(m--){
        for (int j = 0; j < n; j++){
            // nhập dữ liệu và cập nhật
            int a; cin >> a;
            if (a == 0) f[j] = 0;
            else f[j] += 1;
        }

        // tinh l;
        vector <pair<int, int>> q;
        for (int j = 0; j < n; j++){
            while (!q.empty() && q.back().first >= f[j]) q.pop_back();

            if (q.empty()) l[j] = -1;
            else l[j] = q.back().second;

            q.push_back({f[j], j});
        }

        // tinh r
        q.clear();
        for (int j = n-1; j >= 0; j--){
            while (!q.empty() && q.back().first >= f[j]) q.pop_back();

            if (q.empty()) r[j] = n;
            else r[j] = q.back().second;

            q.push_back({f[j], j});
        }

        // updater res;
        for (int j = 0; j < n; j++){
            res = max(res, f[j] * (r[j] - l[j] - 1));
        }
    }

    cout << res;
    return 0;
}