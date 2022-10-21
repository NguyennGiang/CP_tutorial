#include <bits/stdc++.h>
using namespace std;

int n, m[25], vis[25], sum, flag, mid;

void dfs(int num, int len, int s){
    if (flag){
        return;
    }
    if (num == 4){
        flag = 1;
        return;
    }

    if (len == mid){
        dfs(num + 1, 0, 0);
    }

    for (int i = s; i < n; i++){
        if (!vis[i] && len + m[i] <= mid){
            vis[i] = 1;
            dfs(num, len + m[i], i + 1);
            vis[i] = 0;
        }
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        flag = 0;
        sum = 0;
        memset(vis, 0, sizeof(vis));

        cin >> n;
        for (int i = 0; i < n; i++){
            cin >> m[i];
            sum += m[i];
        }
        sort(m, m + n);

        flag = 0;
        mid = sum / 4;
        if (mid * 4 != sum){
            cout << "no\n";
            continue;
        }

        if (m[n-1] > mid) {
            cout << "no\n";
            continue;
        }

        dfs(0, 0, 0);

        cout << (flag ? "yes" : "no") << endl;
    }
    return 0;
}