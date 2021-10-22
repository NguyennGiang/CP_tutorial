#include <bits/stdc++.h>
using namespace std;

int min_st[10005][20], max_st[10005][20];
int a[10005], Log[10005];
int n, k;

void build(){
    for (int k = 1; k < 17; k++){
        for (int i = 0; i + (1 << k) <= n; i++){
            min_st[i][k] = min(min_st[i][k-1], min_st[i + (1 << (k - 1))][k-1]);
            max_st[i][k] = max(max_st[i][k-1], max_st[i + (1 << (k - 1))][k-1]);
        }
    }
}

int minQuery(int l, int r){
    int len = r - l + 1;
    int k = Log[len];
    return min(min_st[l][k], min_st[r - (1 << k) + 1][k]);
}

int maxQuery(int l, int r){
    int len = r - l + 1;
    int k = Log[len];
    return max(max_st[l][k], max_st[r - (1 << k) + 1][k]);
}


int main(){
    cin >> n >> k;
    Log[1] = 0;
    for (int i = 2; i <= n; i++) Log[i] = Log[i/2] + 1;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        min_st[i][0] = max_st[i][0] = a[i];
    }

    build();

    int l = 0, r = 0;
    int maxLen= 0;
    while (r <= n){
        int x = maxQuery(l, r);
        int y = minQuery(l, r);
        maxLen = max(r - l, maxLen);
        if (x - y > k) l++;
        else r++;
    }

    vector <pair <int, int>> ans;
    int cnt = 0;

    for (int i = 0; i <= n - maxLen; i++){
        int x = maxQuery(i , i + maxLen - 1);
        int y = minQuery(i , i + maxLen - 1);
        if (x - y <= k) ans.push_back({i + 1, i + maxLen}), cnt++;
    }
    cout << maxLen << " " << cnt << endl;
    for (auto x : ans){
        cout << x.first << " " << x.second << endl;
    }
    return 0;
}

// Time O(nlogn)