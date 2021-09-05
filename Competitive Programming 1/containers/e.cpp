#include <bits/stdc++.h>

using namespace std; 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; 
    cin >> n;
    int pre = 0; 
    stack <int> num; 
    int oce[n+1];
    memset(oce, 0, sizeof(oce)); 
    for (int i = 0; i < n; i++) {
        int x; 
        cin >> x; 
        oce[x] = 1; 
        if (x > pre) {
            for (int j = pre + 1; j <= x; j++) {
                num.push(j);
            }
            pre = x; 
        }
        while(!num.empty() && oce[num.top()] == 1){
            cout << num.top() << ' ';
            num.pop();
        }
    }
    while(!num.empty()){
        cout << num.top() << " "; 
        num.pop();
    }
    return 0;
}