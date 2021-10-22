#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, l, r;
    string s;
    cin >> n >> l >> r >> s;
    l--, r--;
    deque<char> dq;
    for (int i = l; i <= r; i++) dq.push_back(s[i]);
    stack <char> left, right;
    for (int i = 0; i < l; i++) {
      //cout << s[i] << " ";
      left.push(s[i]);
    }
    for (int i = n - 1; i > r; i--) {
      //cout << s[i];
      right.push(s[i]);
    }
    //cout << endl;
    int m; cin >> m;
    bool flag = 1;
    while (m--){
        char c;
        cin >> c;
        if (c == 'Q'){
            cin >> c;
            if (c == 'L'){
                if (flag){
                    cout << dq.front();
                }
                else cout << dq.back();
            }
            if (c == 'R'){
                if (flag) cout << dq.back();
                else cout << dq.front();

            }
        }
        else if (c == 'S'){
            cin >> c;
            if (c == 'L'){
                cin >> c;
                if(c == 'L'){
                    if (flag){
                        
                        dq.push_front(left.top());
                        left.pop();
                    }
                    else {
                        
                        dq.push_back(left.top());
                        left.pop();
                    }
                }
                else {
                    if (flag){
                        left.push(dq.front());
                        dq.pop_front();
                    }
                    else {
                        left.push(dq.back());
                        dq.pop_back();
                    }
                }
            }
            else {
                cin >> c;
                if (c == 'L'){
                    if (flag){
                        right.push(dq.back());
                        dq.pop_back();
                    }
                    else {
                        right.push(dq.front());
                        dq.pop_front();

                    }
                }
                else {
                    if (flag){
                        dq.push_back(right.top());
                        right.pop();
                    }
                    else {
                        dq.push_front(right.top());
                        right.pop();
                    }
                }
            }
        }
        else {
            flag ^= 1;
        }
    }
    return 0;
}

// Time O(m + n);