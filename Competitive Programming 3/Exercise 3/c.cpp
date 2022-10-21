#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll gcd(int a, int b){
  if (b == 0) return a;
  return gcd(b, a % b);
}

int main(){
  int n, k;
  cin >> n >> k;
  ll lcm = 1;
  for (int i = 0; i < n; i++){
    int x; cin >> x;
    lcm = x * lcm / gcd(x, lcm);
    lcm %= k;
  }
  if (lcm == 0) cout << "YES\n";
  else cout << "NO\n";
  return 0;
}