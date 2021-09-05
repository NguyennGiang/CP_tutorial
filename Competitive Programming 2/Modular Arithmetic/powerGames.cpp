#include <bits/stdc++.h>
using namespace std;

int main(){
    int x, n;
    cin >> x >> n;
    long long fac = 1;
    int cnt[10] = {0};
    for (int i = 1; i <= n; i++){
        fac *= x;
        long long m = fac;

        while(m > 0){
            cnt[m % 10]++;
            m /= 10;
        }
    }
    for (int i : cnt){
        cout << i << " ";
    }
    return 0;
}