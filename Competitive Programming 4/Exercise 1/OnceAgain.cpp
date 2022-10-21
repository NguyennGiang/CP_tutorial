#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1e9;
const int N = 1e5 + 5;
int n, k;
int a[105];
int num[N];
int dp[N];

void solve(){
  cin >> n >> k;
  map<int, int> mp;
  int maxCnt = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    mp[a[i]] ++;
    if (mp[a[i]] > maxCnt){
      maxCnt = mp[a[i]];
    }
  }
  
  int cnt = 0;
  for (int i = 1; i <= min(n, k); i++){
    for (int j = 1; j <= n; j++){
      num[++cnt] = a[j];
    }
  }
  //for (int i = 1; i <= cnt; i++) cout << num[i] << ' ';
  int id = 0;
  
  for (int i = 1; i <= cnt; i++){
    int pos = upper_bound(dp, dp + id, num[i]) - dp;
    if (pos == id) dp[id++] = num[i];
    else dp[pos] = num[i]; 
  }
  // for (int i = 0; i <= id; i++) cout << dp[i] << ' ';
  if (k > n){
    id = id + (k - n) * maxCnt;
  }
  cout << id << endl;
}

int main(){
  int t = 1;
  // cin >> t;
  while(t--){
    solve();
  }
  return 0;
}