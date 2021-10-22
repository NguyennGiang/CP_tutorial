#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, tc;
    cin >> n >> tc;
    deque <int> q;
    for (int x, i = 0; i < n; i++){
        cin >> x;
        q.push_back(x);
    }
    pair <int, int> ans[n];
    for (int i = 1; i < n; i++){
        int x = q.front(); q.pop_front();
        int y = q.front(); q.pop_front();
        ans[i] = {x, y};
        q.push_front(max(x, y));
        q.push_back(min(x, y));
    }

    int a = q[0], b;

    while (tc--){ // O(1 * tc)
        long long k;
        cin >> k;
        if (k < n){
            cout << ans[k].first << " " << ans[k].second << endl;
        }
        else {
            // sau n - 1 lần thực hiện thì số đầu tiên luôn là số lớn nhất, và n - 1 số còn lại có tính chất là lặp lại trạng thái sau n - 1 lần;
            b = (k - n) % (n - 1) + 1;
            cout << a << " " << q[b] << endl;
        }
    }
    return 0;
}

// Time O(tc + n);