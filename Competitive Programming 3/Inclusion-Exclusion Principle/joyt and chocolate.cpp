#include<bits/stdc++.h>
using namespace std;

int main(){
  long long n, a, b, c, d;
  cin >> n >> a >> b >> c >> d;
  long long na = n / a, nb = n / b;
  long long lcm = a * b / __gcd(a, b);
  cout << na * c + nb * d - n / lcm * min(c, d);
  return 0;
}