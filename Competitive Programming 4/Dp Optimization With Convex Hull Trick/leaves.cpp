/*
    gọi dp(i, j) là năng lượng ít nhất để chuyển i lá đầu thành j đống

    dp(i, j) = min(dp(x, j - 1) + năng lượng để chuyển các lá từ x đến i về i);

    năng lương chuyển E = s(i-1) - s(x) - sum(x) * (i-x+1);
    sum(i) = a[1] + a[2] + ... + a[i];
    s(i) = i * a(1) + (i-1) * a[2] + ... + 1 * a[i];

    => dp(i, j) = s(i-1) + min(dp(x, j-1) - s(x) - sum(x) * (x + 1) - sum(x) * i);
*/

#include<bits/stdc++.h>
using namespace std;

const int K = 14;
const int N = 1e5 + 10;

int n, k, a[N], pointer[K];
long long s[N], sum[N], dp[N][K];
vector<long long> U[K], V[K];

bool check(int id, int l1, int l2, int l3){
    return (V[id][l3] - V[id][l1]) * (U[id][l1] - U[id][l2]) < (V[id][l2] - V[id][l1]) * (U[id][l1] - U[id][l3]);
}

void add(int id, long long u, long long v){
    U[id].push_back(u);
    V[id].push_back(v);
    while(U[id].size() >= 3 && check(id, U[id].size() - 3, U[id].size() - 2, U[id].size() - 1)){
        U[id].erase(U[id].end() - 2);
        V[id].erase(V[id].end() - 2);
    }
}

long long get(int id, int x){
    if (pointer[id] >= U[id].size()) pointer[id] = U[id].size() - 1;
    while(pointer[id] < U[id].size() - 1 && U[id][pointer[id]] * x + V[id][pointer[id]] > U[id][pointer[id]+1] * x + V[id][pointer[id]+1])
        pointer[id]++;
    return U[id][pointer[id]] * x + V[id][pointer[id]];
}

int main(){

    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    reverse(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++){
        sum[i] = sum[i-1] + a[i];
        s[i] = s[i-1] + sum[i];
    }
    add(0, 0, 0);

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= k; j++){
            if (j > i) break;
            dp[i][j] = s[i-1] + get(j-1, i);
            add(j, -sum[i], dp[i][j] - s[i] + sum[i] * (i+1));
        }
    }
    cout << dp[n][k];
    return 0;
}