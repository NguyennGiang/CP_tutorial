/*
    - Shortest Subarray With Sum at Least K
    - Leetcode;
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    vector <int> a(n);

    int res = INT_MAX;
    // sử dụng prefix sum để tính tổng các mảng con bắt đầu từ 0 kết thúc tại i;
    deque <int> q;
    for  (int i = 0; i < n; i++){
        cin >> a[i];
        if (i) a[i] += a[i-1];
        if (a[i] >= k){
            res = min(res, i + 1);
        }

        // nếu tồn tại i hiện tại để a[i] - a[q.front()] >= k thì kết quả sẽ tốt hơn khi i = i + 1;
        while (!q.empty() && a[i] - a[q.front()] >= k){
            res = min(res, i - q.front());
            q.pop_front();
        }

        // xóa bỏ tổng tiền tố cao hơn a[i] --> a[i] - a[q.front()] có khả năng là kết quả cao hơn;
        while (!q.empty() && a[i] <= a[q.back()]){
            q.pop_back();
        }

        q.push_back(i);
    }

    if (res == INT_MAX) cout << -1 << endl;
    else cout << res << endl;
    return 0;
}

// Time O(n);