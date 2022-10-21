#include <bits/stdc++.h>
using namespace std;
#define mod 1000000

int main(){
    int f[1005];
    f[0] = f[1] = 1;
    for (int i = 2; i <= 1001; i++){
        f[i] = 0;
        for (int j = 1; j <= i - 1; j++){
            f[i] = (f[i] + (f[j] * f[i-j]) % mod) % mod;
        }
    }

    int n;
    while (cin >> n && n != 0){
        cout << f[n + 1] << endl;
    }
    return 0;
}