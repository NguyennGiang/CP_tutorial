/*
    - Queries with Fixed Length ------ Hackerrank;
*/  

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, q, d;
    cin >> n >> q;
    vector <int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    while (q--){
        deque <int> dq;
        cin >> d;
        int res = 1e6 + 1;
        for (int i = 0; i < n; i++){
            if (!dq.empty() && dq.front() <= i - d){ // loại bỏ phần tử không nằm trong phạm vi subarray đang xét;
                dq.pop_front();
            }
            while (!dq.empty() && a[dq.back()] <= a[i]){ // loại bỏ phần tử <= a[i], vì không có khả năng làm kết quả tốt nhất hiện tại;
                dq.pop_back();
            }
            dq.push_back(i);
            if (i >= d - 1){
                res = min(res, a[dq.front()]); // tìm min của max subarray;
            }
        }
        cout << res << endl;
    }
    return 0;
}

// Time: O(n * q);