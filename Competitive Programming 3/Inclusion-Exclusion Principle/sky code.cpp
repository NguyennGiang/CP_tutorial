#include<bits/stdc++.h>
using namespace std;

const int N = 10000 + 5;
int prime[N], sum[N];
int cnt[N];

void fac(int x){
  int total = 0;
  for (int i = 2; i * i <= x; i++){
    if (x % i == 0){
      prime[total++] = i;
      while(x % i == 0){
        x = x / i;
      }
    }
  }
  if (x > 1){
    prime[total++] = x;
  }
  
  for (int i = 0; i < (1 << total); i++){
    int tmp = 1;
    int num = 0;
    for (int j = 0; j < total; j++){
      if (i & (1 << j)){
        tmp *= prime[j];
        num++;
      }
    }
    cnt[tmp]++;
    sum[tmp] = num;
  }
}

long long C(int n){
  return 1LL * n * (n - 1) * (n - 2) * (n - 3) / 24;
}

int main(){
  int n;
  while(cin >> n){
    memset(cnt, 0, sizeof (cnt));
    for (int i = 0; i < n; i++){
      int x; cin >> x;
      fac(x);
    }
    
    long long ans = 0;
    for (int i = 2; i < N; i++){
      if (cnt[i] >= 4){
        if (sum[i] & 1) ans += C(cnt[i]);
        else ans -= C(cnt[i]);
      }
    }
    
    cout << C(n) - ans << endl;
  }
  return 0;
}