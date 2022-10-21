#include<bits/stdc++.h>
using namespace std;

const int mod = 100000007;

long long c[100005];

int qp(int a, int b){
  if (b == 0) return 1;
  if (b == 1) return a;
  int x = qp(a, b/2);
  x = 1LL * x * x % mod;
  if(b & 1) x = 1LL * x * a % mod;
  return x;
}

void pre(){
  c[0] = 1;
  for (int i = 0; i < 100000; i++){
    c[i + 1] = ((c[i] * (4 * i + 2) % mod) * qp(i + 2, mod - 2)) % mod;
  }
}

int main(){
  int t;
  cin >> t;
  pre();
  unordered_map<long long, bool> mp;
  vector<long long> v;
    for (int i = 2; i <= 100000; i++){
      long long tmp = 1LL * i * i;
      while(tmp <= 10000000000){
        if (mp[tmp] == false){
          mp[tmp] = true;
          v.push_back(tmp);
        }
        tmp *= i;
      }
    }
    
  sort(v.begin(), v.end());

  for (int tc = 1; tc <= t; tc++){
    
    long long a, b;
    cin >> a >> b;
    int na = lower_bound(v.begin(), v.end(), a) - v.begin();
    int nb = upper_bound(v.begin(), v.end(), b) - v.begin();
    
    int n = nb - na;
    
    cout << "Case " << tc << ": " << (n == 0 ? 0: c[n]) << endl;
  }
  return 0;
}