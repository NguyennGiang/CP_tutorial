#include<bits/stdc++.h>
using namespace std;

const int LCM = 504;
int n, k;
vector<int> v;
long long f[20][2][505][(1 << 9) + 10];

long long dp(int i, bool lo, int rem, int last, int mask){
  if (i == n){
    int cnt = 0;
    for (int i = 1; i <= 9; i++){
      if (i == 5) continue;
      if (mask >> (i - 1) & 1){
        if (rem % i == 0){
          cnt++;
        }
      }
    }
    if ((mask >> 4 & 1) && last % 5 == 0){
      cnt++;
    }
    return cnt >= k;
  }
  if (f[i][lo][rem][mask] != -1){
    return f[i][lo][rem][mask];
  }
  long long res = 0;
  int lim = lo? 9 : v[i];
  for (int d = 0; d <= lim; d++){
    int nmask = mask;
    if (d){
      nmask |= (1 << (d - 1));
    }
    res += dp(i + 1, lo || d != v, (rem * 10 + d) % LCM, d, nmask);
  }
  return f[i][lo][rem][mask] = res;
}

long long calc(long long x){
  v.clear();
  while(x){
    v.push_back(x % 10);
    x /= 10;
  }
  reverse(v.begin(), v.end());
  n = v.size();
  memset(f, -1, sizeof(f));
  return dp(0, 0, 0, 0, 0);
}

void solve(){
  long long a, b;
  cin >> a >> b >> k;
  cout << calc(b) - calc(a-1);
}

int main(){
    int t;
    cin >> t;
    while(t--){
      solve();
      cout << '\n';
    }
    return 0;
}