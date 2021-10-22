#include <bits/stdc++.h>
using namespace std;

vector <int> prime;
int ans[1121][15] = {};
void sieve(){
    vector <bool> isPrime(10000, true);
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i * i < 10000; i++){
        if (isPrime[i]){
            for (int j = i * i; j < 10000; j += i){
                isPrime[j] = 0;
            }
        }
    }
    for (int i = 2; i < 10000; i++){
        if(isPrime[i]){
            prime.push_back(i);
        }
    }
}

void build(){
    ans[0][0] = 1;
    for (int i = 0; i < prime.size(); i ++){
        for (int j = 1120; j >= prime[i]; j--){
            for (int k = 1; k < 15; k++){
                ans[j][k] += ans[j-prime[i]][k-1];
            }
        }
    }
}

int main(){
    sieve();
    build();
    int n, m;
    while(1){
        cin >> n >> m;
        if (!n && !m) break;
        cout << ans[n][m] << endl;
    }
    return 0;
}