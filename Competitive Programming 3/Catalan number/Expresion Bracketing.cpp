#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    long long f[30][2];
    f[1][0] = f[2][0] = 1;
    f[1][1] = f[2][1] = 1;

    for (int i = 3; i <= 26; i++){
        f[i][0] = f[i-1][0] * (4 * i - 6) / i;
        f[i][1] = (3 * (2 * i - 3) * f[i-1][1] - (i - 3) * f[i-2][1]) / i;
    }

    while(cin >> n){
        cout << f[n][1] - f[n][0] << endl;
    }
    return 0;
}