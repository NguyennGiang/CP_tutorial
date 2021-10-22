#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int a[N], f[N][20], lg[N];
int n, h, b, e;

void build(){
    lg[1] = 0;
    for (int i = 2; i < N; i++){
        lg[i] = lg[i/2] + 1;
    }
    for (int i = 0; i < n; i++){
        f[i][0] = i;
    }

    for (int k = 1; k < 17; k++){
        for (int i = 0; i + (1 << k) <= n; i++){
            int c1 = f[i][k-1], c2 = f[i + (1 << (k - 1))][k-1];
            f[i][k] = (a[c1] < a[c2] ? c1 : c2);
        }
    }

}

int get(int l, int r){
    int len = lg[r - l + 1];
    int c1 = f[l][len], c2 = f[r - (1 << len) + 1][len];
    return (a[c1] < a[c2] ? c1 : c2);
}

int ans[N];

int main(){
    while (cin >> n){
        cin >> h >> b >> e;
        for (int i = 0; i < n; i++) cin >> a[i];
        build();
        memset(ans, 0, sizeof(ans));
        b--, e--;
        for (int i = 0; i < n; i++){
            int l = max(0, i - h + 1);
            int k = get(l, i);
            ans[k]++;
        }
        for (int i = b; i <= e; i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

// Time O(T * nlogn)
// T : numbers of testcase