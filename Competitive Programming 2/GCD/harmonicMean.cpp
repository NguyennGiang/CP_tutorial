#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(int tc){
  int n;
  cin >> n;
  vector <int> a(n);
  long long x = 1;
  for (int &ai : a) {
    cin >> ai;
    x = 1LL * ai * x;
  }
  long long y = 0;
  for (int ai : a){
    y += x / (1LL * ai);
  }
  x = x * 1LL * n;
  
  long long gcd = __gcd(x, y);
  x = x / gcd;
  y = y / gcd;
  cout << "Case " << tc << ": " << x << "/" << y << '\n';
}

int main(){
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++){
    solve(i);
  }
  return 0;
}