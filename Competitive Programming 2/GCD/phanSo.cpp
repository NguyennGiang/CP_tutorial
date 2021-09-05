#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;

// int gcd(int a, int b){
//   if (b == 0){
//     return a;
//   }
//   return gcd(b, a % b);
// }

int main(){
  string a, b;
  cin >> a >> b;
  int m = pow(10, int(b.length()));
  int t = stoi(a) * m + stoi(b);
  int x = __gcd(m, t);
  cout << t / x << " " << m / x;
  return 0;
}
