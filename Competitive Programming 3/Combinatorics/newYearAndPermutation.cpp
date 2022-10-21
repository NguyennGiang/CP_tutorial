#include<bits/stdc++.h>
using namespace std;


int main(){
  int n, m;
  cin >> n >> m;
  int f[n + 1];
  f[0] = 1;
  for (int i = 1; i <= n; i++) f[i] = 1LL * f[i-1] * i % m;
  
  int res = 0;
  for (int i = 1; i <= n; i++){
    res += (1LL * (1LL * (n - i + 1) * f[i]) % m * f[n-i+1] % m);
    res %= m; 
  }
  cout << res;
}
