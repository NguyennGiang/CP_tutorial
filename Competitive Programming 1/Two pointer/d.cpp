// DPT O(N + M);
#include <bits/stdc++.h>
#define ll long long

const int oo = 1e9; 
using namespace std; 

int main() {
    int m ,n, y0, y1; 
    cin >> m >> n >> y0 >> y1; 
    vector <int> a(m, 0), b(n + 2, 0), time(n + 2, oo);
    for (int i = 0; i < m; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    b[0] = - oo;
    b[n+1] = oo;
    int j = 1;
    int res = 0; 
    for (int i = 0; i < m; i++) {
        while (j < n && b[j] < a[i]) {
            j++;
        }
        if (b[j] == a[i]) {             // Chon cai banh cung vi tri
            if (time[j] == oo) res++;
            time[j] = 0;
        }
        else {
            int l = j - 1, r = j; 
            if (l != 0 && a[i] - b[l] < b[r] - a[i]) {                   // chon mieng phomai ben trai    
                if (time[l] == oo || time[l] == a[i] - b[l]) res++;
                time[l] = min(time[l], a[i] - b[l]);
                continue;
            }
            if (r != m + 1 && a[i] - b[l] > b[r] - a[i]) {               // chon mieng phomai ben phai
                if (time[r] ==  oo || time[r] == b[r] - a[i]) res++;
                time[r] = min(time[r], b[r] - a[i]);
                continue;
            }
            if (l != 0 && (time[l] == oo || time[l] == a[i] - b[l])) {    // neu thoi gian di an ben trai == thowi gian di awn ben phai, uu tien chon sang ben trai trc
                res++;
                time[l] = a[i] - b[l];
                continue;
            }
            if (r != m + 1 && (time[r] == oo || time[r] == b[r] - a[i])) {
                res++;
                time[r] = b[r] - a[i];
                continue;
            }
            if (l != 0 && time[l] > a[i] - b[l]) {
                time[l] = a[i] - b[l];
                continue;
            }
            if (r != m + 1 && time[r] > b[r] - a[i]) {
                time[r] = b[r] - a[i];
            }

        }
    } 
    cout << m - res; 
    return 0;
}