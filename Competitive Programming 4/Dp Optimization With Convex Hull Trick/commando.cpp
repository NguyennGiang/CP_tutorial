/*
    dp(n) = max(dp(k) + adjust(k+1, n)) k = (0...n-1);
    adjust(i, j) = a * sum(i, j) ^ 2 + b * sum(i, j) + c;

    sum[1..x] = f(x);
    dp(n) = dp(k) + a * (f(n) - f(k)) ^ 2 + b * (f(n) - f(k)) + c
    dp(n) = (af(n) ^ 2 + bf(n) + c) + dp(k) - 2af(n)f(k) + af(k)^2 - bf(k) 
    => max : -2af(n) * f(k) + dp(k) + af(k) ^ 2 - bf(k);
*/

#include<bits/stdc++.h>
using namespace std;

const int N = 1000001;
int n, a, b, c;
int x[N];
long long sum[N];
long long dp[N];

vector<long long> M;
vector<long long> B;

// trả về true nếu l1, l3 luôn tốt hơn l2;
bool bad(int l1, int l2, int l3){
    /*
        giao điểm của (l1, l2) là x12 = (b1-b2)/(m2-m1);
        giao điểm của (l1, l3) là x13 = (b1-b3)/(m3-m1);
        x12 > x13;
    */ 
    return (B[l3] - B[l1]) * (M[l1] - M[l2]) < (B[l2] - B[l1]) * (M[l1] - M[l3]);
}

void add(long long m, long long b){
    M.push_back(m);
    B.push_back(b);
    while(M.size() >= 3 && bad(M.size() - 3, M.size() - 2, M.size() - 1)){
        M.erase(M.end() - 2);
        B.erase(B.end() - 2);
    }
}
int pointer;
// trả về tọa độ y nhỏ nhất
long long query(long long x){
    if (pointer >= M.size()){
        pointer = M.size() - 1;
    }
    while(pointer < M.size() - 1 &&
        M[pointer+1] * x + B[pointer + 1] > M[pointer] * x + B[pointer]) pointer++;

    return M[pointer] * x + B[pointer];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        cin >> a >> b >> c;
        for (int i = 1; i<= n; i++){
            cin >> x[i];
            sum[i] = sum[i-1] + x[i];
        }
        dp[1] = a * x[1] * x[1] + b * x[1] + c;
        add(-2 * a * x[1], dp[1] + a * x[1] * x[1] - b * x[1]);
        for (int i = 2; i <= n; i++){
            dp[i] = a * sum[i] * sum[i] + b * sum[i] +c;
            dp[i] = max(dp[i], b * sum[i] + a * sum[i] * sum[i] + c + query(sum[i]));
            add(-2 * a * sum[i], dp[i] + a * sum[i] * sum[i] - b * sum[i]);
        }
        cout << dp[n] << endl;
        M.clear();
        B.clear();
    }
    return 0;
}