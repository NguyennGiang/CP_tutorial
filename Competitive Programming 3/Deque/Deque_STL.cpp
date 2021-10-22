#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int n, k;
        cin >> n >> k;
        deque <int> dq;
        vector <int> res;
        vector <int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
            if (!dq.empty() && dq.front() <= i - k){
                dq.pop_front();
            }
            while (!dq.empty() && a[dq.back()] <= a[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            if (i >= k - 1){
                res.push_back(a[dq.front()]);
            }
        }
        for (int x : res) cout << x << " ";
        cout << endl;
    }
    return 0;
}