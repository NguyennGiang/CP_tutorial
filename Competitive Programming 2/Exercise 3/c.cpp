#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int n, k;
int gift[N][N];

void prefixSum(){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            gift[i][j] = gift[i - 1][j] + gift[i][j-1] - gift[i-1][j-1] + gift[i][j];
        }
    }
}

int getMaxSum(){
    int res = 0;
    for (int i = k; i <= n; i++){
        for (int j = k; j <= n; j++){
            res = max(res, gift[i][j] - gift[i - k][j] - gift[i][j-k] + gift[i-k][j-k]);
        }
    }
    return res;
}

int main(){
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> gift[i][j];
        }
    }
    prefixSum();
    cout << getMaxSum();
    return 0;
}