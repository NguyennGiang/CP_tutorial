#include <bits/stdc++.h>
using namespace std;

bool isPrime[100];

void solve(){
    int k;
    cin >> k;
    string s;
    cin >> s;
    for (int i = 0; i < k; i++){
        if (!isPrime[s[i] - '0']){
            cout << "1\n" << s[i] << '\n';
            return;
        }
    }

    for (int i = 0; i < k; i++){
        for (int j = i + 1; j < k; j++){
            if (!isPrime[(s[i] - '0') * 10 + (s[j] - '0')]){
                cout << "2\n";
                cout << s[i] << s[j] << '\n';
                return;
            }
        }
    }
}

int main(){
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i < 100; i ++){
        if (isPrime[i]){
            for (int j = i * i; j < 100; j+= i){
                isPrime[j] = false;
            }
        }
    }
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}