#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

int main(){
    string num;
    cin >> num;
    int n = num.size();
    ll res = 0;
    ll cur = 0;
    ll cnt = 0;
    for (int i = 0; i < n; i++){
        cnt = (cnt + 1) % mod;
        cur = (cur * 10 + cnt * (num[i] - '0')) % mod;
        res = (res + cur) % mod;
    }
    cout << res;
    return 0;
}