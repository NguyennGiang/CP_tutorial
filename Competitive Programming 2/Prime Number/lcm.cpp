#include <bits/stdc++.h>
using namespace std;

vector <int> primes;
vector <bool> check;

int isPrime(int n){
  check.assign(n + 1, true);
  check[0] = check[1] = false;
  for (int i = 2; i * i <= n; i++){
    if (check[i]){
      for (int j = i * i; j <= n; j += i){
        check[j] = false;
      }
    }
  }
  long long res = 1;
  long long mod = 1e9 + 7;
  for (int i = 2; i <= n; i++){
    if(check[i]){
        int tmp = i;
        while(1LL * tmp * i <= n){
          tmp = (1LL * tmp * i) % mod;
        }
        res = (1LL * res * tmp) % mod;      // Tính tmp
    }
  }
  return res;
}


int main(){
  int n;
  cin >> n;
  cout << isPrime(n);
  return 0;
}
//587943464