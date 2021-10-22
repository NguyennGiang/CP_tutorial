#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while (t--){
        // input;
        int n; cin >> n;
        vector <int> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];

        // a[i] is minimun of longest array [left[i], right[i]];
        deque <int> dq;
        vector <int> left(n + 1), right(n + 1), pre(n + 1), suf(n + 1);
        pre[1] = a[1]; suf[n] = a[n];
        for (int i = 2; i <= n; i++){
            pre[i] = max(pre[i-1], a[i]);
        }

        for (int i = n - 1; i >= 1; i--){
            suf[i] = max(suf[i+1], a[i]);
        }

        for (int i = 1; i <= n; i++){
            while (dq.size() && a[dq.back()] >= a[i]) dq.pop_back();
            if (dq.size() == 0) left[i] = 1;
            else left[i] = dq.back() + 1;
            dq.push_back(i);
        }
        dq.clear();
        for (int i = n; i >= 1; i--){
            while (dq.size() && a[dq.back()] >= a[i]) dq.pop_back();
            if (dq.size() == 0) right[i] = n;
            else right[i] = dq.back() - 1;
            dq.push_back(i);
        }
        //binary search
        bool done = false;
        for (int i = 1; i <= n; i++){
            int x = -1, y = -1;
            int v = a[i];
            int lo = left[i] - 1, hi = i - 1;
            while (lo <= hi){
                int mid = (lo + hi) >> 1;
                if (pre[mid] == v){
                    x = mid;
                    lo = mid + 1;
                }
                else if (pre[mid] > v) hi = mid - 1;
                else lo = mid + 1;
            }
            lo = i + 1, hi = right[i] + 1;
            while (lo <= hi){
                int mid = (lo + hi) >> 1;
                if (suf[mid] == v){
                    y = mid;
                    hi = mid - 1;
                }
                else if (suf[mid] > v) lo = mid + 1;
                else hi = mid - 1;
            }
            if (x == -1 || y == -1) continue;
            cout << "YES\n" << x << " " << y - x - 1 << " " << n - y + 1 << '\n';
            done = true;
            break;
        }
        if (!done) cout << "NO\n";
    }
    return 0;
}

// Time O(t * nlogn)