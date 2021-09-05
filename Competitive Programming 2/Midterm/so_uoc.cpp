#include <bits/stdc++.h>
using namespace std;

int nums_prime[21];

void prime_factor(int n){
    for (int i = 2; i * i <= n; i++){
        while (n % i == 0){
            nums_prime[i] ++;
            n /= i;
        }
    }
    if (n > 1){
        nums_prime[n]++;
    }
}


int main(){
    int n;
    cin >> n;
    memset(nums_prime, 0, sizeof(nums_prime));
    for (int i = 2; i <= n; i++){
        prime_factor(i);
    }
    int answer = 1;
    for (int i = 2; i <= n; i++){
        answer *= (nums_prime[i] + 1);
    }
    cout << answer - 1;
    return 0;
}