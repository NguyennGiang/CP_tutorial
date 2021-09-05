#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int maxn = 100010;

int n, k;
int pre[maxn];
char x[maxn];

bool check(int i, int mid) {
    int r = min(n, i + mid);
    int l = max(1, i - mid);

    return pre[r] - pre[l-1] >= k+1;
}

int main() {
    cin >> n >> k;
    cin >> x + 1;
    
    for (int i = 1; i <= n; i++){
        if (x[i] == '0') {
            pre[i] = pre[i-1] + 1;
        }
        else {
            pre[i] = pre[i-1];
        }
    }
    int l, r, mid;
    int ans = n; 
    for (int i = 1; i <=n; i++) {
        if (x[i] == '1') continue;
        else {
            l = 1; r = n;
            while(l < r){
                mid = (l+r) >> 1;
                if(check(i, mid)) {
                    r = mid;
                }
                else {
                    l = mid + 1;
                }
            }
        }
        ans = min(ans, r);
    }
    cout << ans << endl;
    return 0;
}