#include <bits/stdc++.h>
using namespace std;

vector <int> primes;
vector <bool> check;

void isPrime(int k){
  check.assign(k + 1, true);
  check[0] = check[1] = false;
  for (int i = 2; i * i <= k; i++){
    if (check[i]){
      for (int j = i * i; j <= k; j += i){
        check[j] = false;
      }
    }
  }
  for (int i = 2; i <= k; i++){
    if(check[i]){
      primes.push_back(i);
    }
  }
}

int main(){
  int k;
  cin >> k;
  
  isPrime(k); // nlog(log(n));
  int x, y, z;
  for (x = 0; x < primes.size() - 2; x++){
      for (y = x; y < primes.size() - 1; y++){
        z = k - primes[x] - primes[y];
        if (z >= primes[y] && check[z]){
          cout << primes[x]<< " " << primes[y] << " " << z << endl;
        }
      }
  }
  cout << "0 0 0";
  return 0;
}