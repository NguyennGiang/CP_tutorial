#include<bits/stdc++.h>
using namespace std;

int f[100000];

int main(){
    int cur = 0;
    for (int i = 0; cur <= 60; i++){
        for (int j = 0; j <= i; j++){
            f[cur++] = i;
        }
    }

    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        ans ^= f[x];
    }
    if (ans == 0) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}