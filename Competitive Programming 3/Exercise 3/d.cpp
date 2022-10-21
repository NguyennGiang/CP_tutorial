#include<bits/stdc++.h>
using namespace std;
#define mod 998244353

const int N = 2e5 + 5;
int p[N], d[N];

int main(){
  
  p[0] = 1; 
  for (int i = 1; i < N; i++){
    p[i] = 1LL * p[i-1] * i % mod;
  }
  
  int n; cin >> n;
  for (int i = 1; i < n; i++){
    int a, b; cin >> a >> b;
    d[a]++;
    d[b]++; 
  }
  
  long long ans = n;
  for (int i = 1; i <= n; i++){
    //cout << ans << " " << d[i] << ' ' << p[d[i]] << endl;
    ans = ans * p[d[i]] % mod;
  }
  cout << ans;
  return 0;
}