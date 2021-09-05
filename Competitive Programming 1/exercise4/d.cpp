#include <iostream>
#include <math.h>
#define RASENGAN ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

long long sumOfDigit(long long n){
  if (n < 10){
    return n * (n + 1) / 2;
  }

  long long d = log10(n);

  long long a[d + 1];
  a[0] = 0;
  a[1] = 45;
  for (int i = 2; i <= d; i++){
    a[i] = 10 * a[i - 1] + 45 * pow(10, i - 1);
  }

  long long p = pow(10, d);
  int msd = n / p;

  return msd * a[d] + (msd * (msd - 1) / 2) * p + msd * (1 + n % p) + sumOfDigit(n % p);
}

int main(){
  RASENGAN
  int t;
  cin >> t;
  while(t--){
    long long a, b;
    cin >> a >> b;
    cout << sumOfDigit(b) - sumOfDigit(a - 1) << '\n';
  }
  return 0;
}
