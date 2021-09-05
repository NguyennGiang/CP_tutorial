#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll origin(ll n){
    
    ll res = 1;

    for (ll i = 0; i * i <= n; i++){
        if (n % i == 0){
            while (n % i == 0){
                n /= i;
            }
            res *= i;
        }
    }
    if (n > 1) res *= n;
    return res;
} 

int main(){
    ll m;
    cin >> m;

    for (ll i = m; i >= 1; i--){
        if (i == origin(i)){
            cout << i;
            break;
        }
    }
    return 0;
}