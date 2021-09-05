#include <bits/stdc++.h>
using namespace std;

int num[20];
int d[20][1000];

void solve(int l , int r, int x){
    if (l >= r){
        return;
    }

    int m = (l + r - 1) / 2;
    for (int i = l; i <= m; i++){
        d[x][num[x]++] = i;
    }
    solve(l, m, x + 1);
    solve(m + 1, r, x + 1);
}

int main(){
    int n;
    cin >> n;
    memset(num, 0, sizeof(num));
    int ans = 0;
    while(1 << ans < n){
        ans ++;
    }
    cout << ans << endl;
    solve(1, n, 1);

    for (int i = 1; i <= ans; i++){
        cout << num[i] << " ";
        for (int j = 0; j < num[i]; j++){
            cout << d[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}