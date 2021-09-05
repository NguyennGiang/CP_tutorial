#include <bits/stdc++.h>
using namespace std;
#define ll long long
long long const N = 2e3 + 5;
int n;
ll t[N], c[N], f[N][N];

ll knapSack(int i, ll tym){
    if (tym >= n){
        return 0;
    }
    if (i == n) {
        return 10000000000000L;
    }
    if (f[i][tym]) return f[i][tym];    

    f[i][tym] =  min(knapSack(i + 1, tym), knapSack(i + 1, tym + t[i] + 1) + c[i]);
    
    return f[i][tym];   
}
int main(){
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> t[i] >> c[i];
    }
    cout << knapSack(0, 0) << endl;

    return 0;
}